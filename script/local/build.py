#!/bin/bash
import subprocess
import argparse
import os


def paraser():
    parser = argparse.ArgumentParser(description="build project arg praser")
    parser.add_argument("-clog", "--clean_log_history",
                        help="clearn log history!", type=bool)
    parser.add_argument("-b", "--build", help="build project",
                        type=bool, default=True)
    parser.add_argument("-r", "--run", help="run program",
                    type=bool, default=True)
    return parser.parse_args()


if __name__ == "__main__":
    cmd = paraser()

    if(cmd.clean_log_history):
        print("clean history")
    else:
        print("not clean history")

    if(cmd.build):
        build_cmd = "cmake -S . -B build -G \"Unix Makefiles\""
        print(os.getcwd())
        build = subprocess.run(build_cmd, capture_output=True, shell=True)
        if(build.returncode != 0):
            print("build failed, error is:", build.stderr)
        else:
            print("build succes, build log:", build.stdout.decode('utf-8'))
