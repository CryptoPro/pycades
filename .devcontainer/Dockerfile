ARG VARIANT="base:bookworm"

FROM mcr.microsoft.com/devcontainers/${VARIANT}

ENV DEBIAN_FRONTEND noninteractive

ARG CRYPTOPRO_USERNAME

ARG CRYPTOPRO_PASSWORD

RUN apt-get update && apt-get install -y --no-install-recommends \
    apt-transport-https \
    build-essential \
    ca-certificates \
    cmake \
    git-flow \
    gpg \
    libboost-all-dev \
    python3-dev \
    unzip \
    wget

RUN echo "machine cryptopro.ru login ${CRYPTOPRO_USERNAME} password ${CRYPTOPRO_PASSWORD}" > /etc/apt/auth.conf.d/cryptopro.conf && \
    chmod 600 /etc/apt/auth.conf.d/cryptopro.conf

RUN echo "deb https://cryptopro.ru/repo/deb 5.0-unstable main" > /etc/apt/sources.list.d/cprocsp.list

RUN wget -qO - https://www.cryptopro.ru/sites/default/files/products/csp/cryptopro_key.pub | \
    gpg --dearmor > /etc/apt/trusted.gpg.d/cryptopro.gpg

RUN echo "deb https://repo.rutoken.ru/apt/ stable main" > /etc/apt/sources.list.d/rutoken.list

RUN wget -qO- 'https://dev.rutoken.ru/download/attachments/142508509/repo-rutoken-public.gpg' | \
    gpg --dearmor > /etc/apt/trusted.gpg.d/rutoken.gpg

RUN apt-get update && apt-get install -y --no-install-recommends \
    cprocsp-pki-cades \
    lsb-cprocsp-devel

RUN rm /etc/apt/auth.conf.d/cryptopro.conf

RUN apt-get clean
