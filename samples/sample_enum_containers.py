import pycades

about = pycades.About()
name = about.CSPName(80)
cspInformation = pycades.CspInformation()
cspInformation.InitializeFromName(name)
conts = cspInformation.EnumContainers()

print("Containers: " + str(conts.Count))
for i in range(conts.Count):
    cont = conts.ItemByIndex(i)
    print("  #" + str(i+1) + ".")
    print("  Unique: " + cont.UniqueName)
    print("  Name: " + cont.Name)
    print("  Reader: " + cont.Reader)
    print("  Media: " + cont.Media)
    print("  FQCN: " + cont.FQCN)
    print("  Keys: " + str(cont.Keys.Count))
    for j in range(cont.Keys.Count):
        key = cont.Keys.ItemByIndex(j)
        print("    " + str(j+1) + ".")
        print("    Exportable: " + str(key.IsExportable))
        print("    ExpirationTime: " + key.ExpirationTime)
        if (hasattr(key, 'PublicKey')):
            print("    PublicKey Algorithm: " + key.PublicKey.Algorithm.Value)
            print("    PublicKey KeyLength: " + str(key.PublicKey.Length))
        if (hasattr(key, 'KP_FP')):
            print("    KP_FP: " + key.KP_FP)
        if (hasattr(key, 'KP_ALGID')):
            print("    KP_ALGID: " + str(key.KP_ALGID))
        print("    HasCertificate: " + str(key.HasCertificate))
        if (key.HasCertificate):
            oCertificate = key.Certificate
            oPublicKey = oCertificate.PublicKey();
            print("      Subject:       " + oCertificate.SubjectName);
            print("      Issuer:        " + oCertificate.IssuerName);
            print("      Serial:        " + oCertificate.SerialNumber);
            print("      Valid From:    " + oCertificate.ValidFromDate + " UTC");
            print("      Valid To:      " + oCertificate.ValidToDate + " UTC");
            print("      Thumbprint:    " + oCertificate.Thumbprint);
            print("      Key Algorithm: " + oPublicKey.Algorithm.FriendlyName);
            print("      Key Length:    " + str(oPublicKey.Length));
    print()
