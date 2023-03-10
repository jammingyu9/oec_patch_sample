# Build & Run docker container
```
$ cd oec_patch_sample
$ docker build -t oec_builder_image .
$ docker run -it --name oec_builder oec_builder_image /bin/bash
```

# Build OEC sample inside docker container
## Build x86
```
$ cd ~
$ cd oec_patch_sample
$ mkdir build && cd build
$ cmake -DCMAKE_BUILD_TYPE=Release ..
$ cmake --build .
```
## Build AARCH64
```
$ cd ~
$ cd oec_patch_sample
$ mkdir build && cd build
$ cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=../toolchains/aarch64.cmake ..
$ cmake --build .
```
