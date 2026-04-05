cmake_minimum_required(VERSION 3.10)

project(LabCriptoSimetrica)

add_executable(cripto_simetrica
  src/main.cpp
  src/cesar.cpp
  src/utils.cpp
  src/vigenere.cpp
  src/transposition.cpp
)
