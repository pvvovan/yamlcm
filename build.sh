#!/usr/bin/env bash

# Build application in Linux by cmake

REPO_DIR=$(dirname "$(readlink -f $0)")
BUILD_DIR=${REPO_DIR}/Debug

cmake -S ${REPO_DIR} -B ${BUILD_DIR} -G Ninja
cmake --build  ${BUILD_DIR}
