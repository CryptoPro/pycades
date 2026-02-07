import logging

import pycades

logging.basicConfig(level=logging.INFO)

about = pycades.About()
name = about.CSPName(80)
cspInformation = pycades.CspInformation()
cspInformation.InitializeFromName(name)
conts = cspInformation.EnumContainers()

logging.info("Containers: " + str(conts.Count))
for i in range(conts.Count):
    cont = conts.ItemByIndex(i)
    logging.info("  #" + str(i + 1) + ".")
    logging.info("  Unique: " + cont.UniqueName)
    logging.info("  Name: " + cont.Name)
    logging.info("  Reader: " + cont.Reader)
    logging.info("  Media: " + cont.Media)
    logging.info("  FQCN: " + cont.FQCN)
    logging.info("  Keys: " + str(cont.Keys.Count))
    for j in range(cont.Keys.Count):
        key = cont.Keys.ItemByIndex(j)
        logging.info("    " + str(j + 1) + ".")
        logging.info("    Exportable: " + str(key.IsExportable))
        logging.info("    ExpirationTime: " + key.ExpirationTime)
        if hasattr(key, "PublicKey"):
            logging.info(
                "    PublicKey Algorithm: " + key.PublicKey.Algorithm.Value,
            )
            logging.info(
                "    PublicKey KeyLength: " + str(key.PublicKey.Length),
            )
        if hasattr(key, "KP_FP"):
            logging.info("    KP_FP: " + key.KP_FP)
        if hasattr(key, "KP_ALGID"):
            logging.info("    KP_ALGID: " + str(key.KP_ALGID))
        logging.info("    HasCertificate: " + str(key.HasCertificate))
        if key.HasCertificate:
            oCertificate = key.Certificate
            oPublicKey = oCertificate.PublicKey()
            logging.info("      Subject:       " + oCertificate.SubjectName)
            logging.info("      Issuer:        " + oCertificate.IssuerName)
            logging.info("      Serial:        " + oCertificate.SerialNumber)
            logging.info(
                "      Valid From:    " + oCertificate.ValidFromDate + " UTC",
            )
            logging.info(
                "      Valid To:      " + oCertificate.ValidToDate + " UTC",
            )
            logging.info("      Thumbprint:    " + oCertificate.Thumbprint)
            logging.info(
                "      Key Algorithm: " + oPublicKey.Algorithm.FriendlyName,
            )
            logging.info("      Key Length:    " + str(oPublicKey.Length))
