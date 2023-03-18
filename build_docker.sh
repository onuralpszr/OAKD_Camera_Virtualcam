#!/bin/sh

podman build --progress=plain . -t fedora-oak:latest -f Dockerfile
