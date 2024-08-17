#!/bin/sh

podman build --progress=plain . -t fedora-oak:latest -f Dockerfile.fedora
podman build --progress=plain . -t ubuntu-oak:latest -f Dockerfile.ubuntu
