Пример использования pycades
===
Для работы примеров необходим сертификат с привязкой к закрытому ключу.

Тестовый сертификат можно установить с помощью команды:
```bash
export PATH="/opt/cprocsp/bin/amd64:/opt/cprocsp/bin/aarch64:$PATH" && \
cryptcp -createcert -dn "CN=test" -provtype 80 -cont '\\.\HDIMAGE\test' -ca https://cryptopro.ru/certsrv
```

В данном разделе
---

[Пример создания и проверки подписи](../samples/sign_verify.py)<br>
[Пример создания и проверки отделенной подписи формата CAdES-BES по хэш-значению данных](../samples/signhash_verifyhash.py)<br>
[Пример создания и проверки подписи документа XML](../samples/sign_verify_xml.py)<br>
[Пример шифрования и расшифрования данных](../samples/encrypt_decrypt.py)<br>
[Пример перечисления контейнеров](../samples/enum_containers.py)<br>

