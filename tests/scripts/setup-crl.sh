#!/bin/bash

export PATH="/opt/cprocsp/bin/amd64:/opt/cprocsp/bin/aarch64:$PATH"

# Configuration
CRL_FILE="tests/fixtures/pycades-root.crl"
SEARCH_TERM="pycades-root"
STORE="uCA"

echo "Checking for CRL: $SEARCH_TERM in $STORE..."

# 1. Check if the CRL exists in the intermediate (uCA) store
if certmgr -list -crl -store "$STORE" | grep -q "$SEARCH_TERM"; then
    echo "✔ CRL already installed. Skipping."
else
    echo "✘ CRL not found. Installing..."

    # 2. Verify fixture file exists
    if [[ ! -f "$CRL_FILE" ]]; then
        echo "Error: CRL file not found at $CRL_FILE"
        exit 1
    fi

    # 3. Install the CRL
    echo 'o' | certmgr -install -crl -file "$CRL_FILE" -store "$STORE"

    # 4. Verification
    if [[ $? -eq 0 ]]; then
        echo "✔ Successfully installed CRL."
    else
        echo "✖ Failed to install CRL."
        exit 1
    fi
fi
