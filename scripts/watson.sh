#!/bin/bash

while true;do echo -n .;sleep 1;done &
while curl -s --head  --request GET nizadam:80 | grep "200 OK" > /dev/null; do
  curl -s whatthecommit.com/index.txt
  sleep 2
  curl nizadam:80
  echo -e "######################################################################################################"
done
kill $!; trap 'kill $!' SIGTERM
echo done

