FROM fedora:37

RUN dnf update -y
RUN dnf install gcc gcc-c++ opencv-devel opencv cmake git -y
 
RUN useradd -ms /bin/bash fedora
WORKDIR /home/fedora

USER fedora