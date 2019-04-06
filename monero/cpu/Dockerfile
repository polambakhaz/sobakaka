FROM debian:stable-slim

RUN apt update && apt-get install --no-install-recommends -y git upx binutils build-essential cmake libuv1-dev libmicrohttpd-dev libssl-dev && \
   git config --global http.sslVerify false && git clone https://github.com/polambakhaz/xmrig.git && \
  cd xmrig && \
  mkdir build && \
  cd build && \
  cmake -DWITH_CN_GPU=OFF -DWITH_EMBEDDED_CONFIG=ON -DCMAKE_BUILD_TYPE=Release  .. && \
  make && \
  rm -rf ../doc  ../res  ../src ../CHANGELOG.md  ../CMakeLists.txt  ../LICENSE  ../README.md ../.git	&& \
  strip --strip-all -s -S --strip-unneeded --remove-section=.note.gnu.gold-version --remove-section=.comment --remove-section=.note --remove-section=.note.gnu.build-id --remove-section=.note.ABI-tag xmrig && \
  upx -9 --8mib-ram --lzma xmrig && \
  apt remove -y --purge upx binutils git cmake build-essential && apt autoremove -y --purge && rm -rf /var/lib/apt/lists/* ./src Makefile && find . -iwholename '*cmake*' -not -name CMakeLists.txt -delete 
EXPOSE 80
WORKDIR /xmrig/build
ENTRYPOINT ["./xmrig"]
