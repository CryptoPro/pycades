# cp -r ~/linux-amd64_deb/ .
# docker build -t pycades-build .

FROM ubuntu:latest

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        git \
        cmake \
        build-essential \
        libboost-all-dev \
        ca-certificates \
        python3-dev && \
    rm -rf /var/lib/apt/lists/*

RUN update-ca-certificates

COPY linux-amd64_deb csp

RUN ./csp/install.sh

RUN apt-get update && apt-get install -y --no-install-recommends \
        ./csp/cprocsp-rdr-gui-gtk* \
        ./csp/lsb-cprocsp-devel* \
        ./csp/cprocsp-legacy* \
        ./csp/cprocsp-pki-cades* && \
    rm -rf /var/lib/apt/lists/*

COPY . /pycades/

WORKDIR /pycades

RUN make

RUN SCRIPTS_DIR=./tests/scripts && \
    chmod +x ${SCRIPTS_DIR}/*.sh && \
    ${SCRIPTS_DIR}/setup-root.sh && \
    ${SCRIPTS_DIR}/setup-leaf.sh && \
    ${SCRIPTS_DIR}/setup-crl.sh

# docker run pycades-build python3 samples/sign_verify.py
