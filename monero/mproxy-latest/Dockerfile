FROM alpine:latest as build
RUN apk add --update --no-cache upx binutils libuv-dev git cmake git build-base libmicrohttpd-dev openssl-dev libuuid util-linux-dev
RUN git clone https://github.com/polambakhaz/xmrig-proxy && \
	cd xmrig-proxy && \
	mkdir build && \
	cd build && \
	cmake -DCMAKE_BUILD_TYPE=Release -DWITH_HTTPD=OFF .. && \
	make 
FROM alpine:latest
COPY --from=build /xmrig-proxy/build/xmrig-proxy /xmrig-proxy
ADD config.json /config.json
EXPOSE 3333 2222
WORKDIR /
ENTRYPOINT  ["/xmrig-proxy"]
