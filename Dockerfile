FROM ubuntu:20.04
ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update
RUN apt-get install -y git gcc g++ gcc-aarch64-linux-gnu g++-aarch64-linux-gnu cmake vim

RUN useradd -m semits
USER semits

RUN git clone https://github.com/jammingyu9/oec_patch_sample.git /home/semits/oec_patch_sample
