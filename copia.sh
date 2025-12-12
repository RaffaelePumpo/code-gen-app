#!/bin/bash

DESTINAZIONE="/home/rpumpo/Github/code-gen-app/src"
mkdir -p "$DESTINAZIONE"

FILE_DA_COPIARE=(
    # Copy HarnessControl files
    "/mnt/c/Users/rpumpo/Desktop/Github/code-gen-app/codegen/HarnessControl_ert_rtw/HarnessControl.cpp"
    "/mnt/c/Users/rpumpo/Desktop/Github/code-gen-app/codegen/HarnessControl_ert_rtw/HarnessControl.h"
    "/mnt/c/Users/rpumpo/Desktop/Github/code-gen-app/codegen/HarnessControl_ert_rtw/HarnessControl_private.h"
    "/mnt/c/Users/rpumpo/Desktop/Github/code-gen-app/codegen/HarnessControl_ert_rtw/HarnessControl_types.h"
    #"/mnt/c/Users/rpumpo/Desktop/Github/code-gen-app/codegen/HarnessControl_ert_rtw/ert_main.cpp" 

    # Copy Control files
    "/mnt/c/Users/rpumpo/Desktop/Github/code-gen-app/codegen/slprj/ert/Control/Control.cpp"
    "/mnt/c/Users/rpumpo/Desktop/Github/code-gen-app/codegen/slprj/ert/Control/Control.h"
    "/mnt/c/Users/rpumpo/Desktop/Github/code-gen-app/codegen/slprj/ert/Control/Control_private.h"
    "/mnt/c/Users/rpumpo/Desktop/Github/code-gen-app/codegen/slprj/ert/Control/Control_types.h"

    # Copy _sharedutils files
    "/mnt/c/Users/rpumpo/Desktop/Github/code-gen-app/codegen/slprj/ert/_sharedutils/EmergencyT.h"
    "/mnt/c/Users/rpumpo/Desktop/Github/code-gen-app/codegen/slprj/ert/_sharedutils/rtwtypes.h"

    # Copy Fault files
    "/mnt/c/Users/rpumpo/Desktop/Github/code-gen-app/codegen/slprj/ert/Fault/Fault.cpp"
    "/mnt/c/Users/rpumpo/Desktop/Github/code-gen-app/codegen/slprj/ert/Fault/Fault.h"
    "/mnt/c/Users/rpumpo/Desktop/Github/code-gen-app/codegen/slprj/ert/Fault/Fault_private.h"
    "/mnt/c/Users/rpumpo/Desktop/Github/code-gen-app/codegen/slprj/ert/Fault/Fault_types.h"

    # Copy LQR files
    "/mnt/c/Users/rpumpo/Desktop/Github/code-gen-app/codegen/slprj/ert/LQR/LQR.cpp"
    "/mnt/c/Users/rpumpo/Desktop/Github/code-gen-app/codegen/slprj/ert/LQR/LQR.h"
    "/mnt/c/Users/rpumpo/Desktop/Github/code-gen-app/codegen/slprj/ert/LQR/LQR_private.h"
    "/mnt/c/Users/rpumpo/Desktop/Github/code-gen-app/codegen/slprj/ert/LQR/LQR_types.h"

    # Copy Manager_1 files
    "/mnt/c/Users/rpumpo/Desktop/Github/code-gen-app/codegen/slprj/ert/Manager_1/Manager_1.cpp"
    "/mnt/c/Users/rpumpo/Desktop/Github/code-gen-app/codegen/slprj/ert/Manager_1/Manager_1.h"
    "/mnt/c/Users/rpumpo/Desktop/Github/code-gen-app/codegen/slprj/ert/Manager_1/Manager_1_private.h"
    "/mnt/c/Users/rpumpo/Desktop/Github/code-gen-app/codegen/slprj/ert/Manager_1/Manager_1_types.h"

)


echo "Copying in $DESTINAZIONE..."
all_files_found=true

for file in "${FILE_DA_COPIARE[@]}"
do
    if [ -e "$file" ]; then
        cp -f "$file" "$DESTINAZIONE/"
        echo "✓ Done: $file"
    else
        echo "✗ Non trovato: $file"
        ls -la "$(dirname "$file")"
        all_files_found=false
    fi
done

if [ "$all_files_found" = true ]; then
    echo "All files copied successfully in $DESTINAZIONE."
fi
