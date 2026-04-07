.DEFAULT_GOAL := build-library

.PHONY: help
help: ## Display this help screen
	@grep -E '^[a-z.A-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'

.PHONY: clean
clean: clean-build clean-test clean-pyc  ## Clean project

.PHONY: clean-build
clean-build:
	rm -fr build/
	rm -fr dist/
	rm -fr .eggs/
	rm -fr .mypy_cache
	rm -fr .ruff_cache
	rm -rf .py-build-cmake_cache
	rm -fr samples/*.so
	find . -name '*.egg-info' -not -path '.venv/*' -exec rm -fr {} +
	find . -name '*.egg' -not -path '.venv/*' -exec rm -f {} +

.PHONY: clean-pyc
clean-pyc:
	find . -name '*.pyc' -not -path '.venv/*' -exec rm -f {} +
	find . -name '*.pyo' -not -path '.venv/*' -exec rm -f {} +
	find . -name '*~' -not -path '.venv/*' -exec rm -f {} +
	find . -name '__pycache__' -not -path '.venv/*' -exec rm -fr {} +

.PHONY: clean-test
clean-test:
	rm -fr .tox/
	rm -fr .nox/
	rm -f .coverage
	rm -fr htmlcov/

.PHONY: library
library: build-library ## Build shared library

.PHONY: build-library
build-library:
	cmake -S . -B build
	cmake --build build -j$$(nproc)

.PHONY: rebuild-library
rebuild-library: clean build-library ## Clean and rebuild the library from scratch

.PHONY: package
package: build-package ## Build python package

.PHONY: build-package
build-package: clean
	uv build
