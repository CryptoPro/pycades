.DEFAULT_GOAL := build

# =========================
# LD_LIBRARY_PATH paths
# =========================
CPROCSP_LIB_AMD64 := /opt/cprocsp/lib/amd64
CPROCSP_LIB_X86   := /opt/cprocsp/lib/ia32
CPROCSP_LIB_ARM   := /opt/cprocsp/lib/aarch64:/opt/cprocsp/lib/arm64
CPROCSP_LIB_PATHS := $(CPROCSP_LIB_AMD64):$(CPROCSP_LIB_X86):$(CPROCSP_LIB_ARM)

TARGETS := \
	help \
	clean clean-build clean-uv \
	build rebuild \
	uv-install uv \
	docker-build docker

.PHONY: $(TARGETS)

help: ## Display this help screen
	@grep -E '^[a-z.A-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "$(CYAN)%-30s$(RESET) %s\n", $$1, $$2}'

clean: clean-build clean-uv ## Clean project

clean-build:
	rm -fr build
	rm -fr samples/*.so
	rm -fr .py-build-cmake_cache

clean-uv:
	rm -fr dist/
	rm -fr .venv
	rm -fr uv.lock

build: ## Build shared library
	cmake -S . -B build
	cmake --build build -j$$(nproc)

rebuild: clean build ## Clean and rebuild the library from scratch

uv-install: ## Install extension in virtual environment
	uv venv --clear
	uv pip install -v .

uv: uv-install ## Run sample in virtual environment
	LD_LIBRARY_PATH=$(CPROCSP_LIB_PATHS) uv run --with . samples/sign_verify.py

docker-build: ## Build docker image for pycades
	docker build -t pycades-build .

docker: docker-build ## Run sample in docker
	docker run pycades-build python3 samples/sign_verify.py

# =========================
# Printing out targets
# =========================
GREEN := \033[38;2;0;255;128m
CYAN  := \033[38;5;51m
RESET := \033[0m

define inject_start_hook
.PHONY: .print-start-$1
.print-start-$1:
	@printf "$(GREEN)>>> Running target: [%s]$(RESET)\n" "$1"

$1: .print-start-$1
endef
$(foreach t,$(TARGETS),$(eval $(call inject_start_hook,$t)))