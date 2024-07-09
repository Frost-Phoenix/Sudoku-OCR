{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  buildInputs = with pkgs;  [ 
    gnumake
    gcc
    # raylib
    clang-tools
    criterion
  ];
}

# format all files: find . -iname '*.h' -o -iname '*.c' | xargs clang-format --style=file -i
