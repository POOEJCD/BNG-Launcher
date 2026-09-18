#!/usr/bin/env bash
#
# instalar-logos.sh — coloca el icono y el fondo de BNG Launcher
#
# Uso:
#   1. Copia esta carpeta bng-assets/ y este script dentro de BNG-Launcher/
#   2. cd ~/Desktop/BNG-Launcher
#   3. bash instalar-logos.sh
#   4. git add -A && git commit -m "Logo e icono de BNG Launcher" && git push

set -euo pipefail

echo "instalar-logos.sh  version 1"
echo

if [ ! -f "program_info/CMakeLists.txt" ]; then
    echo "Error: ejecuta esto desde la raiz del repo BNG-Launcher." >&2
    exit 1
fi

if [ ! -d "bng-assets" ]; then
    echo "Error: falta la carpeta bng-assets/ junto a este script." >&2
    exit 1
fi

echo "==> 1/3  Instalando el icono"

cp bng-assets/bnglauncher.ico            program_info/bnglauncher.ico
cp bng-assets/BNGLauncher_256.png        program_info/org.bnglauncher.BNGLauncher_256.png
cp bng-assets/org.bnglauncher.BNGLauncher.svg \
                                         program_info/org.bnglauncher.BNGLauncher.svg
# El icono de la barra de titulo sale del tema activo, no de program_info
cp bng-assets/launcher.svg  launcher/resources/fluent_dark/scalable/launcher.svg
cp bng-assets/launcher.svg  launcher/resources/fluent/scalable/launcher.svg
cp bng-assets/launcher.svg  launcher/resources/multimc/scalable/launcher.svg

echo "==> 2/3  Instalando el logotipo como fondo"

cp bng-assets/bng-background.png  launcher/resources/backgrounds/bng.png

# Registrar el fondo en el qrc
sed -i 's|<qresource prefix="/backgrounds">|<qresource prefix="/backgrounds">\
        <file alias="bng">bng.png</file>|' \
    launcher/resources/backgrounds/backgrounds.qrc

# Registrar el catpack en el gestor de temas
sed -i 's|    if (!m_catPacksFolder.mkpath("\."))|    addCatPack(std::make_unique<FreesmCatPack>("bng", QObject::tr("BNG Launcher")));\
\
    if (!m_catPacksFolder.mkpath("."))|' \
    launcher/ui/themes/ThemeManager.cpp

echo "==> 3/3  Poniendo el fondo BNG por defecto"

sed -i 's|m_settings->registerSetting("BackgroundCat", QString("kitteh"));|m_settings->registerSetting("BackgroundCat", QString("bng"));|' \
    launcher/Application.cpp
sed -i 's|m_settings->registerSetting("TheCat", false);|m_settings->registerSetting("TheCat", true);|' \
    launcher/Application.cpp
# Marca de agua discreta, no a todo volumen
sed -i 's|m_settings->registerSetting("CatOpacity", 100);|m_settings->registerSetting("CatOpacity", 18);|' \
    launcher/Application.cpp

echo
echo "Listo. Revisa con:  git status"
echo "Luego:  git add -A && git commit -m 'Logo e icono de BNG Launcher' && git push"
