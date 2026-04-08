# cp -r ~/csp/ .
# docker build -t pycades-build .

ARG PYTHON_VER=3.12

FROM python:${PYTHON_VER}

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        git \
        cmake \
        build-essential \
        libboost-all-dev \
        ca-certificates && \
    rm -rf /var/lib/apt/lists/*

RUN update-ca-certificates

COPY csp csp

RUN ./csp/install.sh

RUN apt-get update && apt-get install -y --no-install-recommends \
        ./csp/cprocsp-rdr-gui-gtk* \
        ./csp/lsb-cprocsp-devel* \
        ./csp/cprocsp-legacy* \
        ./csp/cprocsp-pki-cades* && \
    rm -rf /var/lib/apt/lists/*

COPY . /pycades/

WORKDIR /pycades

RUN make clean && make

RUN SCRIPTS_DIR=./tests/scripts && \
    chmod +x ${SCRIPTS_DIR}/*.sh && \
    ${SCRIPTS_DIR}/setup-root.sh && \
    ${SCRIPTS_DIR}/setup-leaf.sh && \
    ${SCRIPTS_DIR}/setup-crl.sh

# docker run pycades-build python3 samples/sign_verify.py
