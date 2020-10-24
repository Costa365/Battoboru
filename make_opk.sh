#!/bin/sh

OPK_NAME=battoboru.opk

echo ${OPK_NAME}

# create default.gcw0.desktop
cat > default.gcw0.desktop <<EOF
[Desktop Entry]
Name=Battobōru
Comment=Bat and Ball game
Exec=battoboru.gcw
Terminal=false
Type=Application
StartupNotify=true
Icon=battoboru
Categories=applications;
EOF

# create opk
FLIST="media"
FLIST="${FLIST} battoboru.gcw"
FLIST="${FLIST} battoboru.png"
FLIST="${FLIST} default.gcw0.desktop"

rm -f ${OPK_NAME}
mksquashfs ${FLIST} ${OPK_NAME} -all-root -no-xattrs -noappend -no-exports

cat default.gcw0.desktop
rm -f default.gcw0.desktop

