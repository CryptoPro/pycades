.DEFAULT_GOAL := build-library

.PHONY: help
help: ## Display this help screen
	@grep -E '^[a-z.A-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'

.PHONY: clean
clean: clean-build ## Clean project

.PHONY: clean-build
clean-build:
	rm -fr build
	rm -fr samples/*.so

.PHONY: build-library
build-library: clean ## Build shared library
	cmake -S . -B build
	cmake --build build -j$(nproc)