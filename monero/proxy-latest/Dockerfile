FROM alpine:latest
RUN apk add --update --no-cache libuv-dev git upx binutils cmake git build-base libmicrohttpd-dev openssl-dev util-linux-dev && \
        git clone https://github.com/polambakhaz/xmrig-proxy && \
        cd xmrig-proxy && \
        mkdir build && \
        cd build && \
        cmake -DCMAKE_BUILD_TYPE=Release .. && \
        make && \
        rm -rf ./src Makefile CMakeFiles CMakeCache.txt && \
        find . -name '*cmake*' -delete && \
        rm -rf ../doc  ../res  ../src ../CHANGELOG.md  ../CMakeLists.txt  ../LICENSE  ../README.md ../.git ../cmake
RUN apk del --no-cache --purge cmake git build-base upx binutils
EXPOSE 3333 2222
ADD config.json /xmrig-proxy/build/config.json
WORKDIR /xmrig-proxy/build
ENTRYPOINT  ["./xmrig-proxy"]
