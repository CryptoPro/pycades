Сборка расширения для языка Python
===


## Dockerfile

В качестве примера сборки в репозитории представлен [Dockerfile](../Dockerfile).

Для построения образа и проверки работы расширения необходимо: 
1. В директории с Dockerfile поместить папку с пакетами из [архива с КриптоПро CSP](https://cryptopro.ru/products/csp/downloads):
    ```bash
    cp -r ~/csp/ .
    ```
1. Собрать образ:
    ```bash
    docker build -t pycades-build .
    ```
1. Выполнить пример:
    ```
    docker run pycades-build python3 samples/sign_verify.py
    ```


## Ubuntu

Сборка производится на Ubuntu 24.04 + КриптоПро CSP 5.0.13000 + Python 3.12

1. Установить необходимые пакеты для сборки:
    ```
    sudo apt install cmake build-essential libboost-all-dev python3-dev
    ```
1. Скачать [архив с КриптоПро CSP](https://cryptopro.ru/products/csp/downloads), 
распаковать этот архив и установить КриптоПро CSP, а также пакеты lsb-cprocsp-devel, cprocsp-pki-cades, cprocsp-legacy:
    ```
    tar xvf linux-amd64_deb.tgz
    cd linux-amd64_deb
    sudo ./install.sh lsb-cprocsp-devel cprocsp-legacy cprocsp-pki-cades
    ```
1. Скачать исходный код pycades
    ```
    git clone https://github.com/CryptoPro/pycades.git
    cd pycades
    ```
1. Выполнить сборку:
    ```
    make || make rebuild-library
    ```
