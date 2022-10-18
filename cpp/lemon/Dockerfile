FROM ubuntu:latest
RUN apt-get update -y \
  && DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends \
     build-essential bison flex time curl gdb cmake git nano \
     ca-certificates \
  && rm -rf /var/lib/apt/lists/* && update-ca-certificates

WORKDIR /app
EXPOSE 8000

RUN mkdir -p /usr/local/lemon
COPY lemon/lemon.c /usr/local/lemon
COPY lemon/lempar.c /usr/local/lemon
RUN gcc -o /usr/local/bin/lemon /usr/local/lemon/lemon.c

RUN echo  export PATH='"'/app/bin:/app/bin/$(uname -s)-$(uname -m):/app/node_modules/.bin:/app:'${PATH}''"' >> /root/.bashrc
ENTRYPOINT ["/bin/bash","-i","-c","\"$@\"","--"]

