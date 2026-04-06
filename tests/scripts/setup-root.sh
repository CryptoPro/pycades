#!/bin/bash

export PATH="/opt/cprocsp/bin/amd64:/opt/cprocsp/bin/aarch64:$PATH"

# Configuration
ROOT_CERT="tests/fixtures/pycades-root.cer"
SEARCH_TERM="pycades-root"

echo "Checking for Root CA: $SEARCH_TERM..."

# 1. Check if the Root CA exists in the uRoot store
if certmgr -list -store uRoot | grep -q "$SEARCH_TERM"; then
    echo "✔ Root CA already installed. Skipping."
else
    echo "✘ Root CA not found. Installing..."

    # 2. Verify fixture exists
    if [[ ! -f "$ROOT_CERT" ]]; then
        echo "Error: Root certificate file not found at $ROOT_CERT"
        exit 1
    fi

    # 3. Install the certificate
    echo 'o' | certmgr -install -file "$ROOT_CERT" -store uRoot

    # 4. Final check
    if [[ $? -eq 0 ]]; then
        echo "✔ Successfully installed Root CA."
    else
        echo "✖ Failed to install Root CA."
        exit 1
    fi
fi
