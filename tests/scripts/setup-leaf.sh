#!/bin/bash

export PATH="/opt/cprocsp/bin/amd64:/opt/cprocsp/bin/aarch64:$PATH"

# Configuration
PFX_FILE="tests/fixtures/pycades-test.pfx"
SEARCH_TERM="pycades-test"

echo "Checking for certificate: $SEARCH_TERM..."

# 1. Check if the certificate exists in the personal (uMy) store
if certmgr -list -store uMy | grep -q "$SEARCH_TERM"; then
    echo "✔ Certificate already installed. Skipping."
else
    echo "✘ Certificate not found. Installing..."

    # 2. Check if the fixture file actually exists
    if [[ ! -f "$PFX_FILE" ]]; then
        echo "Error: Fixture file not found at $PFX_FILE"
        exit 1
    fi

    # 3. Attempt installation
    certmgr -install -pfx -file "$PFX_FILE" -newpin ""

    # 4. Final verification of the exit code
    if [[ $? -eq 0 ]]; then
        echo "✔ Successfully installed $SEARCH_TERM."
    else
        echo "✖ Failed to install certificate."
        exit 1
    fi
fi
