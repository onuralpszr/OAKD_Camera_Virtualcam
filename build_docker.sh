#!/bin/sh

podman build --progress=plain . -t fedora-oak:latest -f docker/Dockerfile.fedora
podman build --progress=plain . -t ubuntu-oak:latest -f docker/Dockerfile.ubuntu
