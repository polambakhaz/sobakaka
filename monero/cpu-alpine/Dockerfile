FROM  alpine:3.8
RUN   adduser -S -D -H -h /xmrig miner && \
      apk --no-cache upgrade && \
      apk --no-cache add \
        git \
        cmake \
        libuv-dev \
        build-base libmicrohttpd-dev openssl-dev && \
        git config --global http.sslVerify false && git clone https://github.com/polambakhaz/xmrig && \
      cd xmrig && \
      mkdir build && \
      cd build && \
      cmake -DWITH_EMBEDDED_CONFIG=ON -DCMAKE_BUILD_TYPE=Release .. && \
      make && \
      rm -rf ./src Makefile CMakeFiles CMakeCache.txt && \
      find . -name '*cmake*' -delete && \
      rm -rf ../doc  ../res  ../src ../CHANGELOG.md  ../CMakeLists.txt  ../LICENSE  ../README.md ../.git ../cmake && \
      apk del --no-cache --purge \
        build-base \
        cmake \
        git
USER miner
EXPOSE 80
WORKDIR    /xmrig/build
ENTRYPOINT  ["./xmrig"]
