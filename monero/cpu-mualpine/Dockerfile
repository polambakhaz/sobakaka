FROM  alpine:latest as build
RUN   apk --no-cache upgrade && \
      apk --no-cache add \
        git \
        cmake \
        libuv-dev \
        upx binutils build-base libmicrohttpd-dev openssl-dev && \
        git config --global http.sslVerify false && git clone https://github.com/polambakhaz/xmrig && \
      cd xmrig && \
      mkdir build && \
      cd build && \
      cmake -DWITH_HTTPD=OFF -DWITH_CN_GPU=OFF -DWITH_EMBEDDED_CONFIG=ON -DCMAKE_BUILD_TYPE=Release .. && \
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
FROM alpine:latest  
COPY --from=build /xmrig/build/xmrig .
ENTRYPOINT ["./xmrig"]
