#!/bin/bash

BIN="./release/FLOWCROWDS"
ARG="./data/params.lua"

export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:"./release"
$BIN $ARG

