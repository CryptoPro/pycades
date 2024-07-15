Сборка расширения для языка Python
===
Сборка производится на Ubuntu 23.10.

1. Установить необходимые пакеты для сборки:
```
sudo apt install cmake build-essential libboost-all-dev python3-dev unzip
```
2. Скачать [архив с КриптоПро CSP](https://cryptopro.ru/products/csp/downloads), 
распаковать этот архив и установить КриптоПро CSP:
```
tar xvf linux-amd64_deb.tgz
cd linux-amd64_deb
sudo ./install.sh
```
3. Установить пакет cprocsp-devel:
```
sudo apt install ./lsb-cprocsp-devel_5.0*.deb
```
4. Если используется [КриптоПро CSP 5.0 R3 (сборка 5.0.12900 Selene)](https://www.cryptopro.ru/forum2/default.aspx?g=posts&m=142169#post142169) и выше, 
то все необходимые пакеты CAdES входят в состав дистрибутива КриптоПро CSP 5.0 R3, их не надо скачивать и ставить отдельно.<br/>
Для более ранних версий CSP скачать архив с [КриптоПро ЭЦП SDK](https://cryptopro.ru/products/cades/downloads), 
распаковать этот архив и установить пакет cprocsp-pki-cades (версия не ниже 2.0.14892)
```
tar xvf cades_linux_amd64.tar.gz
cd cades_linux_amd64
sudo apt install ./cprocsp-pki-cades*.deb
```
5. Скачать и распаковать архив с исходниками [pycades](https://cryptopro.ru/sites/default/files/products/cades/pycades/pycades.zip):
```
unzip pycades.zip
cd pycades_*
```
6. Задать значение переменной Python_INCLUDE_DIR в файле CMakeLists.txt (папка с Python.h). 
7. Если сборка осуществляется на arm64, то применить патч для поддержки arm64:
```
patch < ./arm64_support.patch
```
8. Выполнить сборку:
```
mkdir build
cd build
cmake ..
make -j4
```
