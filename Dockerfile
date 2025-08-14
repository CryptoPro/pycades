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
        ./csp/cprocsp-pki-cades* && \
    rm -rf /var/lib/apt/lists/*

RUN git clone https://github.com/CryptoPro/pycades.git

WORKDIR /pycades

RUN PY_VERSION=$(python3 --version | awk '{print $2}' | cut -d. -f1-2) && \
    sed -i "s/3\\.11/$PY_VERSION/g" CMakeLists.txt

RUN mkdir build && cd build && \
    cmake .. && \
    make -j$(nproc)

# docker run -it pycades-build
# /opt/cprocsp/bin/amd64/cryptcp -createcert -dn "CN=test" -provtype 80 -cont '\\.\HDIMAGE\test' -ca https://cryptopro.ru/certsrv
# python3 sample_sign_verify.py
