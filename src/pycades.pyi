"""pycades реализует интерфейс, аналогичный CAdESCOM.

Расширение предназначено для встраивания криптографических операций в серверные приложения на языке Python3 с использованием сертифицированного СКЗИ КриптоПро CSP.
"""

from _typeshed import Incomplete
from typing import Any

ANSI_X923_PADDING: int
AT_KEYEXCHANGE: int
AT_SIGNATURE: int
CADESCOM_ATTRIBUTE_OTHER: int
CADESCOM_AUTHENTICATED_ATTRIBUTE_DOCUMENT_DESCRIPTION: int
CADESCOM_AUTHENTICATED_ATTRIBUTE_DOCUMENT_NAME: int
CADESCOM_AUTHENTICATED_ATTRIBUTE_SIGNING_TIME: int
CADESCOM_AllowNoOutstandingRequest: int
CADESCOM_AllowNone: int
CADESCOM_AllowUntrustedCertificate: int
CADESCOM_AllowUntrustedRoot: int
CADESCOM_BASE64_TO_BINARY: int
CADESCOM_CADES_A: int
CADESCOM_CADES_BES: int
CADESCOM_CADES_DEFAULT: int
CADESCOM_CADES_T: int
CADESCOM_CADES_X_LONG_TYPE_1: int
CADESCOM_CONTAINER_STORE: int
CADESCOM_CURRENT_USER_STORE: int
CADESCOM_DISPLAY_DATA_ATTRIBUTE: int
CADESCOM_DISPLAY_DATA_CONTENT: int
CADESCOM_DISPLAY_DATA_NONE: int
CADESCOM_ENCODE_ANY: int
CADESCOM_ENCODE_BASE64: int
CADESCOM_ENCODE_BINARY: int
CADESCOM_ENCRYPTION_ALGORITHM_3DES: int
CADESCOM_ENCRYPTION_ALGORITHM_AES: int
CADESCOM_ENCRYPTION_ALGORITHM_DES: int
CADESCOM_ENCRYPTION_ALGORITHM_GOST_28147_89: int
CADESCOM_ENCRYPTION_ALGORITHM_RC2: int
CADESCOM_ENCRYPTION_ALGORITHM_RC4: int
CADESCOM_HASH_ALGORITHM_CP_GOST_3411: int
CADESCOM_HASH_ALGORITHM_CP_GOST_3411_2012_256: int
CADESCOM_HASH_ALGORITHM_CP_GOST_3411_2012_256_HMAC: int
CADESCOM_HASH_ALGORITHM_CP_GOST_3411_2012_512: int
CADESCOM_HASH_ALGORITHM_CP_GOST_3411_2012_512_HMAC: int
CADESCOM_HASH_ALGORITHM_CP_GOST_3411_HMAC: int
CADESCOM_HASH_ALGORITHM_MD2: int
CADESCOM_HASH_ALGORITHM_MD4: int
CADESCOM_HASH_ALGORITHM_MD5: int
CADESCOM_HASH_ALGORITHM_SHA1: int
CADESCOM_HASH_ALGORITHM_SHA_256: int
CADESCOM_HASH_ALGORITHM_SHA_384: int
CADESCOM_HASH_ALGORITHM_SHA_512: int
CADESCOM_LOCAL_MACHINE_STORE: int
CADESCOM_MEMORY_STORE: int
CADESCOM_PKCS7_TYPE: int
CADESCOM_STRING_TO_UCS2LE: int = 0x00
CADESCOM_SkipInstallToStore: int
CADESCOM_XADES_A: int
CADESCOM_XADES_BES: int
CADESCOM_XADES_DEFAULT: int
CADESCOM_XADES_T: int
CADESCOM_XADES_X_LONG_TYPE_1: int
CADESCOM_XMLDSIG_TYPE: int
CADESCOM_XML_SIGNATURE_TYPE_ENVELOPED: int
CADESCOM_XML_SIGNATURE_TYPE_ENVELOPING: int
CADESCOM_XML_SIGNATURE_TYPE_TEMPLATE: int
CAPICOM_AUTHENTICATED_ATTRIBUTE_DOCUMENT_DESCRIPTION: int
CAPICOM_AUTHENTICATED_ATTRIBUTE_DOCUMENT_NAME: int
CAPICOM_AUTHENTICATED_ATTRIBUTE_SIGNING_TIME: int
CAPICOM_CA_STORE: str
CAPICOM_CERTIFICATE_FIND_APPLICATION_POLICY: int
CAPICOM_CERTIFICATE_FIND_CERTIFICATE_POLICY: int
CAPICOM_CERTIFICATE_FIND_EXTENDED_PROPERTY: int
CAPICOM_CERTIFICATE_FIND_EXTENSION: int
CAPICOM_CERTIFICATE_FIND_ISSUER_NAME: int
CAPICOM_CERTIFICATE_FIND_KEY_USAGE: int
CAPICOM_CERTIFICATE_FIND_ROOT_NAME: int
CAPICOM_CERTIFICATE_FIND_SHA1_HASH: int
CAPICOM_CERTIFICATE_FIND_SUBJECT_NAME: int
CAPICOM_CERTIFICATE_FIND_TEMPLATE_NAME: int
CAPICOM_CERTIFICATE_FIND_TIME_EXPIRED: int
CAPICOM_CERTIFICATE_FIND_TIME_NOT_YET_VALID: int
CAPICOM_CERTIFICATE_FIND_TIME_VALID: int
CAPICOM_CERTIFICATE_INCLUDE_CHAIN_EXCEPT_ROOT: int
CAPICOM_CERTIFICATE_INCLUDE_END_ENTITY_ONLY: int
CAPICOM_CERTIFICATE_INCLUDE_WHOLE_CHAIN: int
CAPICOM_CERT_INFO_ISSUER_DNS_NAME: int
CAPICOM_CERT_INFO_ISSUER_EMAIL_NAME: int
CAPICOM_CERT_INFO_ISSUER_SIMPLE_NAME: int
CAPICOM_CERT_INFO_ISSUER_UPN: int
CAPICOM_CERT_INFO_SUBJECT_DNS_NAME: int
CAPICOM_CERT_INFO_SUBJECT_EMAIL_NAME: int
CAPICOM_CERT_INFO_SUBJECT_SIMPLE_NAME: int
CAPICOM_CERT_INFO_SUBJECT_UPN: int
CAPICOM_CURRENT_USER_STORE: int
CAPICOM_DATA_ENCIPHERMENT_KEY_USAGE: int
CAPICOM_DIGITAL_SIGNATURE_KEY_USAGE: int
CAPICOM_EKU_CLIENT_AUTH: int
CAPICOM_EKU_CODE_SIGNING: int
CAPICOM_EKU_EMAIL_PROTECTION: int
CAPICOM_EKU_ENCRYPTING_FILE_SYSTEM: int
CAPICOM_EKU_OTHER: int
CAPICOM_EKU_SERVER_AUTH: int
CAPICOM_EKU_SMARTCARD_LOGON: int
CAPICOM_ENCODE_ANY: int
CAPICOM_ENCODE_BASE64: int
CAPICOM_ENCODE_BINARY: int
CAPICOM_ENCRYPTION_KEY_LENGTH_128_BITS: int
CAPICOM_ENCRYPTION_KEY_LENGTH_192_BITS: int
CAPICOM_ENCRYPTION_KEY_LENGTH_256_BITS: int
CAPICOM_ENCRYPTION_KEY_LENGTH_40_BITS: int
CAPICOM_ENCRYPTION_KEY_LENGTH_56_BITS: int
CAPICOM_ENCRYPTION_KEY_LENGTH_MAXIMUM: int
CAPICOM_LOCAL_MACHINE_STORE: int
CAPICOM_MY_STORE: str
CAPICOM_OID_KEY_USAGE_EXTENSION: int
CAPICOM_OID_OTHER: int
CAPICOM_OTHER_STORE: str
CAPICOM_PROPID_ENHKEY_USAGE: int
CAPICOM_PROPID_KEY_PROV_INFO: int
CAPICOM_ROOT_STORE: str
CAPICOM_STORE_OPEN_MAXIMUM_ALLOWED: int
CRYPT_MODE_CBCRFC4357: int
CRYPT_MODE_CBCSTRICT: int
CRYPT_MODE_CNT: int
CRYPT_MODE_CTR: int
CRYPT_MODE_GCM: int
CRYPT_MODE_MGM: int
CRYPT_MODE_OMAC_CTR: int
CRYPT_MODE_WRAP: int
CRYPT_MODE_WRAP_PAD: int
DISABLE_EVERY_CARRIER_OPERATION: int
ENABLE_ANY_CARRIER_TYPE: int
ENABLE_ANY_OPERATION: int
ENABLE_CARRIER_CREATE: int
ENABLE_CARRIER_OPEN_ENUM: int
ENABLE_CARRIER_TYPE_CSP: int
ENABLE_CARRIER_TYPE_FKC_NO_SM: int
ENABLE_CARRIER_TYPE_FKC_SM: int
ISO10126_PADDING: int
ISO_IEC_7816_4_PADDING: int
MEDIA_TYPE_CLOUD: int
MEDIA_TYPE_HDIMAGE: int
MEDIA_TYPE_REGISTRY: int
MEDIA_TYPE_SCARD: int
PKCS5_PADDING: int
RANDOM_PADDING: int
TLS_1_0_PADDING: int
XCN_CRYPT_STRING_BASE64HEADER: int
XmlDsigGost3410Url: str
XmlDsigGost3410Url2012256: str
XmlDsigGost3410Url2012512: str
XmlDsigGost3410UrlObsolete: str
XmlDsigGost3411Url: str
XmlDsigGost3411Url2012256: str
XmlDsigGost3411Url2012512: str
XmlDsigGost3411UrlObsolete: str
ZERO_PADDING: int


class About:
    """CAdESCOM.About

    Версия библиотеки.
    """

    @property
    def Version(self) -> str:
        """Возвращает строковое представление версии."""
        ...

    @property
    def MajorVersion(self) -> int:
        """Возвращает старший компонент версии."""
        ...

    @property
    def MinorVersion(self) -> int:
        """Возвращает младший компонент версии."""
        ...

    @property
    def BuildVersion(self) -> int:
        """Возвращает номер сборки."""
        ...
    # TODO что такое версия плагина и ее отличие от Version

    @property
    def PluginVersion(self) -> Version:
        """Возвращает объект Version c версией плагина."""
        ...

    def __init__(self): ...
    def CSPVersion(self, provName: str = "",
                   provType: int = 75) -> Version:
        """Возвращает объект Version c версией криптопровайдера (CSP) производства компании Крипто-Про."""
        ...


class Version:
    """CAdESCOM.Version

    Описывает версию
    """
    @property
    def MajorVersion(self) -> int:
        """Возвращает старший компонент версии."""
        ...

    @property
    def MinorVersion(self) -> int:
        """Возвращает младший компонент версии."""
        ...

    @property
    def BuildVersion(self) -> int:
        """Возвращает номер сборки."""
        ...

    def toString(self) -> str:
        """Возвращает строковое представление версии."""
        ...


class Attribute:
    """CAdESCOM.CPAttribute

    Атрибут усовершенствованной подписи (подписанный или неподписанный).
    Объект CPAttribute предоставляет средства для работы с отдельным атрибутом усовершенствованной подписи.
    """
    OID: OID
    """Возвращает объектный идентификатор (OID) атрибута."""
    Name: int
    """Имя атрибута. Данное свойство аналогично свойству Name объекта CAPICOM.Attribute"""
    Value: str
    """Возвращает закодированное значение атрибута."""
    ValueEncoding: int
    """Способ кодирования значения атрибута."""

    def __init__(self) -> None: ...


class OID:
    FriendlyName: str
    Name: int
    Value: str


class CRL:
    """CAdESCOM.CRL

    Объект для работы со списком отозванных сертификатов.
    """
    @property
    def AuthKeyID(self) -> str:
        """Возвращает информацию об идентификаторе ключа УЦ, издавшего список отозванных сертификатов."""
        ...

    @property
    def IssuerName(self) -> str:
        """Возвращает информацию об издателе списка отозванных серификатов."""
        ...

    @property
    def NextUpdate(self) -> str:
        """Возвращает информацию о дате следующего обновления списка отозванных сертификатов."""
        ...

    @property
    def ThisUpdate(self) -> str:
        """Возвращает информацию о дате выпуска списка отозванных сертификатов."""
        ...

    @property
    def Thumbprint(self) -> str:
        """Возвращает информацию об отпечатке списка отозванных сертификатов, позволяющем однозначно идентифицировать список."""
        ...

    @classmethod
    def __init__(cls, *args, **kwargs) -> None: ...

    def Export(self, encodingType: int) -> str:
        """Экспортирует список отозванных сертификатов.

        Args:
            encodingType: Кодировка, в которой производится экспорт. (CAPICOM_ENCODING_TYPE) 

        Returns:
            Строковое представление списка отозванных сертификатов в указанной кодировке.

        CAPICOM_ENCODING_TYPE:
            - CAPICOM_ENCODE_ANY
            - CAPICOM_ENCODE_BASE64
            - CAPICOM_ENCODE_BINARY
        """
        ...

    def Import(self, blobCRL: str) -> None:
        """Инициализирует список отозванных сертификатов."""
        ...


class Certificate:
    """CAdESCOM.CPCertificate

    Описывает сертификат открытого ключа.
    """
    @property
    def IssuerName(self) -> str:
        """Издатель сертификата."""
        ...

    @property
    def PrivateKey(self) -> Incomplete:  # TODO
        """Закрытый ключ."""
        ...

    @property
    def SerialNumber(self) -> str:
        """Серийный номер."""
        ...

    @property
    def SubjectName(self) -> str:
        """Имя субъекта."""
        ...

    @property
    def Thumbprint(self) -> str:
        """Отпечаток."""
        ...

    @property
    def ValidFromDate(self) -> str:
        """Дата, с которой сертификат действителен."""
        ...

    @property
    def ValidToDate(self) -> str:
        """Дата, до которой сертификат действителен."""
        ...

    @property
    def Version(self) -> int:
        """Версия сертификата."""
        ...

    def __init__(self) -> None: ...

    def AdditionalStore(self, store: Store) -> None:
        """Передать в объект дополнительное хранилище для проверки статуса сертификата."""
        ...

    def BasicConstraints(self) -> Incomplete:
        """Возвращает объект BasicConstraints для данного сертификата."""
        ...

    def Export(self, encodingType: int) -> str:
        """Экспортирует сертификат в виде закодированной строки.

        Args:
            encodingType: Кодировка, в которой производится экспорт. (CAPICOM_ENCODING_TYPE) 

        Returns:
            Строковое представление сертификата в заданной кодировке.

        CAPICOM_ENCODING_TYPE:
            - CAPICOM_ENCODE_ANY
            - CAPICOM_ENCODE_BASE64
            - CAPICOM_ENCODE_BINARY
        """
        ...

    def ExtendedKeyUsage(self) -> Incomplete:
        """Возвращает объект ExtendedKeyUsage для данного сертификата."""
        ...

    def FindPrivateKey(self, criteria: Any = None):
        """
        Производит поиск закрытого ключа соответствующего сертификату открытого ключа и устанавливает ссылку на него. 
        В случае отсутствия в системе подходящего ключа порождает исключение.

        Args:
            criteria: Зарезервировано. Не используется.
        """
        ...

    def GetInfo(self, infoType: int) -> str:
        """Возвращает информацию из сертификата.

        Args:
            infoType: CAPICOM_CERT_INFO_TYPE

        Returns:
            Значение, в зависимости от infoType

        CAPICOM_CERT_INFO_TYPE:
            - CAPICOM_CERT_INFO_SUBJECT_SIMPLE_NAME - Returns the display name from the certificate subject.
            - CAPICOM_CERT_INFO_ISSUER_SIMPLE_NAME - Returns the display name of the issuer of the certificate.
            - CAPICOM_CERT_INFO_SUBJECT_EMAIL_NAME - Returns the email address of the certificate subject.
            - CAPICOM_CERT_INFO_ISSUER_EMAIL_NAME - Returns the email address of the issuer of the certificate.
            - CAPICOM_CERT_INFO_SUBJECT_UPN - Returns the UPN of the certificate subject. Introduced in CAPICOM 2.0.
            - CAPICOM_CERT_INFO_ISSUER_UPN - Returns the UPN of the issuer of the certificate. Introduced in CAPICOM 2.0.
            - CAPICOM_CERT_INFO_SUBJECT_DNS_NAME - Returns the DNS name of the certificate subject. Introduced in CAPICOM 2.0.
            - CAPICOM_CERT_INFO_ISSUER_DNS_NAME - Returns the DNS name of the issuer of the certificate. Introduced in CAPICOM 2.0.
        """
        ...

    def HasPrivateKey(self) -> bool:
        """Имеется ли закрытый ключ для сертификата."""
        ...

    def Import(self, encodedData: str | bytes) -> None:
        """Импортирует сертификат из закодированной строки."""
        ...

    def IsValid(self, *args, **kwargs) -> CertificateStatus:
        """Является ли сертификат валидным."""
        ...

    def KeyUsage(self) -> Incomplete:
        """Возвращает объект KeyUsage для данного сертификата."""
        ...

    def PublicKey(self) -> PublicKey:
        """Возвращает объект PublicKey для данного сертификата."""
        ...


class Certificates:
    """CAdESCOM.Certificates

    Описывает коллекцию сертификатов. Реализует интерфейс, аналогичный интерфейсу объекта CAPICOM.Certificates.
    Объект данного класса нельзя создать. Данный объект возвращает свойство Certificates объектов Store и CadesSignedData.
    В отличие от объекта Microsoft CAPICOM.Certificates, для данного объекта реализованы только следующие методы и свойства: Find, Item, Count.
    """

    @property
    def Count(self) -> int:
        """Возвращает количество объектов в коллекции сертификатов."""
        ...

    def Item(self, index: int) -> Certificate:
        """Возвращает сертификат с заданным индексом из коллекции.

        Args:
            index: Индекс сертификата.
        """
        ...

    def Find(self,
             findType: int,
             criteria: int | str = CAPICOM_CERTIFICATE_FIND_SHA1_HASH,
             validOnly: int = int(False)) -> Certificate:
        """Возвращает коллекцию сертификатов, удовлетворяющих заданному критерию.

        Более подробно аргументы расписаны здесь:
        https://learn.microsoft.com/en-us/windows/win32/seccrypto/certificates-find

        Args:
            findType: CAPICOM_CERTIFICATE_FIND_TYPE
            criteria: Данные для поиска. Время передается в виде строки вида "YYYYMMDDhhmmss.ddddddZ" 
            validOnly: Возвращать только валидные сертификаты
        """
        ...


class CertificateStatus:
    """CAdESCOM.CertificateStatus

    Описывает статус сертификата открытого ключа.
    Объект данного класса нельзя создать.
    Данный объект возвращает метод IsValid объекта Certificate.
    В отличие от объекта Microsoft CAPICOM.CertificateStatus, для данного объекта реализованы только свойство ValidationCertificates, ErrorStatuses, Result.
    """

    ValidationCertificates: Incomplete
    """Возвращает коллекцию сертификатов из цепочки."""

    ErrorStatus: Incomplete
    """Свойство для получения значения поля dwErrorStatus структуры CERT_TRUST_STATUS для каждого из сертификатов цепочки."""

    Result: bool
    """Является ли сертификат валидным."""


class PublicKey:
    """
    CAdESCOM.PublicKey

    Описывает открытый ключ сертификата.
    """
    @property
    def Algorithm(self) -> OID:
        """Возвращает OID алгоритма открытого ключа."""
        ...

    @property
    def EncodedKey(self) -> Incomplete:
        """Возвращает значение открытого ключа."""
        ...

    @property
    def EncodedParameters(self) -> Incomplete:
        """Возвращает параметры алгоритма открытого ключа."""
        ...

    @property
    def Length(self) -> int:
        """Возвращает длину открытого ключа в битах."""
        ...


class PrivateKey:
    ContainerName: str
    KeySpec: int
    ProviderName: str
    ProviderType: int
    UniqueContainerName: str

    def ChangePin(self, *args, **kwargs):
        """Exists in lib but not documented"""
        ...


class EnvelopedData:
    Algorithm: Incomplete
    Content: Incomplete
    ContentEncoding: Incomplete
    Recipients: Incomplete
    @classmethod
    def __init__(cls, *args, **kwargs) -> None: ...
    def Decrypt(self, *args, **kwargs): ...
    def Encrypt(self, *args, **kwargs): ...
    def StreamDecrypt(self, *args, **kwargs): ...
    def StreamEncrypt(self, *args, **kwargs): ...


class HashedData:
    Algorithm: Incomplete
    DataEncoding: Incomplete
    Key: Incomplete
    Value: Incomplete
    @classmethod
    def __init__(cls, *args, **kwargs) -> None: ...
    def Hash(self, *args, **kwargs): ...
    def SetHashValue(self, *args, **kwargs): ...


class RawSignature:
    @classmethod
    def __init__(cls, *args, **kwargs) -> None: ...
    def SignHash(self, *args, **kwargs): ...
    def VerifyHash(self, *args, **kwargs): ...


class SignedData:
    Certificates: Incomplete
    Content: Incomplete
    ContentEncoding: Incomplete
    Signers: Incomplete
    @classmethod
    def __init__(cls, *args, **kwargs) -> None: ...
    def AdditionalStore(self, *args, **kwargs): ...
    def CoSign(self, *args, **kwargs): ...
    def CoSignCades(self, *args, **kwargs): ...
    def CoSignHash(self, *args, **kwargs): ...
    def EnhanceCades(self, *args, **kwargs): ...
    def Sign(self, *args, **kwargs): ...
    def SignCades(self, *args, **kwargs): ...
    def SignHash(self, *args, **kwargs): ...
    def Verify(self, *args, **kwargs): ...
    def VerifyCades(self, *args, **kwargs): ...
    def VerifyHash(self, *args, **kwargs): ...


class SignedXML:
    Content: Incomplete
    DigestMethod: Incomplete
    SignatureMethod: Incomplete
    SignatureType: Incomplete
    Signers: Incomplete
    @classmethod
    def __init__(cls, *args, **kwargs) -> None: ...
    def Sign(self, *args, **kwargs): ...
    def Verify(self, *args, **kwargs): ...


class Signer:
    AuthenticatedAttributes: Incomplete
    CRLs: Incomplete
    Certificate: Incomplete
    CheckCertificate: Incomplete
    KeyPin: Incomplete
    OCSPResponses: Incomplete
    Options: Incomplete
    SignatureStatus: Incomplete
    SignatureTimeStampTime: Incomplete
    SigningTime: Incomplete
    TSAAddress: Incomplete
    UnauthenticatedAttributes: Incomplete
    @classmethod
    def __init__(cls, *args, **kwargs) -> None: ...


class Store:
    Certificates: Certificates
    Location: Incomplete
    Name: Incomplete
    @classmethod
    def __init__(cls, *args, **kwargs) -> None: ...
    def Add(self, *args, **kwargs): ...
    def AddCRL(self, *args, **kwargs): ...
    def Close(self, *args, **kwargs): ...
    def Open(self, *args, **kwargs): ...


class SymmetricAlgorithm:
    DiversData: Incomplete
    IV: Incomplete
    LegacyPluginSymmetricExport: Incomplete
    @classmethod
    def __init__(cls, *args, **kwargs) -> None: ...
    def Decrypt(self, *args, **kwargs): ...
    def DiversifyKey(self, *args, **kwargs): ...
    def Encrypt(self, *args, **kwargs): ...
    def ExportKey(self, *args, **kwargs): ...
    def GenerateKey(self, *args, **kwargs): ...
    def ImportKey(self, *args, **kwargs): ...
    def SetMode(self, *args, **kwargs): ...
    def SetPadding(self, *args, **kwargs): ...


def ModuleVersion() -> str:
    """Версия pycades"""
    ...
