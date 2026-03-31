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

RUN git clone https://github.com/CryptoPro/pycades.git

# for development purposes
# COPY . /pycades/

WORKDIR /pycades

RUN mkdir build && cd build && \
    cmake .. && \
    make -j$(nproc)

# docker run -it -w /pycades/samples/ pycades-build
# /opt/cprocsp/bin/amd64/cryptcp -createcert -dn "CN=test" -provtype 80 -cont '\\.\HDIMAGE\test' -ca https://cryptopro.ru/certsrv
# python3 sign_verify.py
