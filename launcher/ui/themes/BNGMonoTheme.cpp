// SPDX-License-Identifier: GPL-3.0-only
/*
 *  BNG Launcher - Minecraft Launcher
 *  Copyright (C) 2026 BNG Launcher Contributors
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, version 3.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#include "BNGMonoTheme.h"

#include <QObject>

QString BNGMonoTheme::id()
{
    return "bng-mono";
}

QString BNGMonoTheme::name()
{
    return QObject::tr("BNG Mono");
}

QString BNGMonoTheme::tooltip()
{
    return QObject::tr("Minimalist monochrome theme");
}

QPalette BNGMonoTheme::colorScheme()
{
    QPalette mono;
    mono.setColor(QPalette::Window, QColor(0x10, 0x10, 0x10));
    mono.setColor(QPalette::WindowText, QColor(0xE8, 0xE8, 0xE8));
    mono.setColor(QPalette::Base, QColor(0x0A, 0x0A, 0x0A));
    mono.setColor(QPalette::AlternateBase, QColor(0x16, 0x16, 0x16));
    mono.setColor(QPalette::ToolTipBase, QColor(0x1C, 0x1C, 0x1C));
    mono.setColor(QPalette::ToolTipText, QColor(0xE8, 0xE8, 0xE8));
    mono.setColor(QPalette::Text, QColor(0xE8, 0xE8, 0xE8));
    mono.setColor(QPalette::Button, QColor(0x1A, 0x1A, 0x1A));
    mono.setColor(QPalette::ButtonText, QColor(0xE8, 0xE8, 0xE8));
    mono.setColor(QPalette::BrightText, QColor(0xFF, 0xFF, 0xFF));
    mono.setColor(QPalette::Link, QColor(0xB0, 0xB0, 0xB0));
    mono.setColor(QPalette::Highlight, QColor(0xE8, 0xE8, 0xE8));
    mono.setColor(QPalette::HighlightedText, QColor(0x0A, 0x0A, 0x0A));
    mono.setColor(QPalette::PlaceholderText, QColor(0x6E, 0x6E, 0x6E));
    return fadeInactive(mono, fadeAmount(), fadeColor());
}

double BNGMonoTheme::fadeAmount()
{
    return 0.55;
}

QColor BNGMonoTheme::fadeColor()
{
    return QColor(0x6E, 0x6E, 0x6E);
}

bool BNGMonoTheme::hasStyleSheet()
{
    return true;
}

QString BNGMonoTheme::appStyleSheet()
{
    return QStringLiteral(R"BNGCSS(
QToolTip {
    background-color: #1C1C1C;
    color: #E8E8E8;
    border: 1px solid #2E2E2E;
    padding: 4px 6px;
}

QMainWindow, QDockWidget, QDialog {
    background-color: #101010;
}

QToolBar {
    background-color: #101010;
    border: none;
    border-bottom: 1px solid #1E1E1E;
    padding: 4px 6px;
    spacing: 2px;
}
QToolBar::separator {
    background-color: #2E2E2E;
    width: 1px;
    margin: 6px 6px;
}

QToolButton {
    background-color: transparent;
    color: #E8E8E8;
    border: 1px solid transparent;
    border-radius: 3px;
    padding: 5px 9px;
}
QToolButton:hover {
    background-color: #242424;
    border-color: #2E2E2E;
}
QToolButton:pressed, QToolButton:checked, QToolButton:on {
    background-color: #E8E8E8;
    color: #0A0A0A;
    border-color: #E8E8E8;
}

QPushButton {
    background-color: #1A1A1A;
    color: #E8E8E8;
    border: 1px solid #2E2E2E;
    border-radius: 3px;
    padding: 5px 14px;
    min-height: 18px;
}
QPushButton:hover {
    background-color: #242424;
    border-color: #5A5A5A;
}
QPushButton:pressed {
    background-color: #E8E8E8;
    color: #0A0A0A;
}
QPushButton:default {
    border-color: #6E6E6E;
}
QPushButton:disabled {
    background-color: #141414;
    color: #5A5A5A;
    border-color: #1E1E1E;
}

QLineEdit, QTextEdit, QPlainTextEdit, QSpinBox, QDoubleSpinBox {
    background-color: #0A0A0A;
    color: #E8E8E8;
    border: 1px solid #2E2E2E;
    border-radius: 3px;
    padding: 4px 6px;
    selection-background-color: #E8E8E8;
    selection-color: #0A0A0A;
}
QLineEdit:focus, QTextEdit:focus, QPlainTextEdit:focus,
QSpinBox:focus, QDoubleSpinBox:focus {
    border-color: #6E6E6E;
}

QComboBox {
    background-color: #1A1A1A;
    color: #E8E8E8;
    border: 1px solid #2E2E2E;
    border-radius: 3px;
    padding: 4px 8px;
}
QComboBox:hover {
    border-color: #5A5A5A;
}
QComboBox::drop-down {
    border: none;
    width: 18px;
}
QComboBox QAbstractItemView {
    background-color: #161616;
    color: #E8E8E8;
    border: 1px solid #2E2E2E;
    selection-background-color: #E8E8E8;
    selection-color: #0A0A0A;
    outline: none;
}

QListView, QTreeView, QTableView {
    background-color: #0A0A0A;
    alternate-background-color: #121212;
    color: #E8E8E8;
    border: 1px solid #1E1E1E;
    outline: none;
}
QListView::item, QTreeView::item, QTableView::item {
    padding: 3px;
    border-radius: 2px;
}
QListView::item:hover, QTreeView::item:hover, QTableView::item:hover {
    background-color: #1E1E1E;
}
QListView::item:selected, QTreeView::item:selected, QTableView::item:selected {
    background-color: #E8E8E8;
    color: #0A0A0A;
}

QHeaderView::section {
    background-color: #161616;
    color: #A8A8A8;
    border: none;
    border-right: 1px solid #1E1E1E;
    border-bottom: 1px solid #1E1E1E;
    padding: 5px 6px;
}

QTabWidget::pane {
    border: 1px solid #1E1E1E;
    top: -1px;
}
QTabBar::tab {
    background-color: transparent;
    color: #8A8A8A;
    border: none;
    border-bottom: 2px solid transparent;
    padding: 7px 14px;
    margin-right: 2px;
}
QTabBar::tab:hover {
    color: #E8E8E8;
}
QTabBar::tab:selected {
    color: #FFFFFF;
    border-bottom-color: #E8E8E8;
}

QScrollBar:vertical {
    background: transparent;
    width: 10px;
    margin: 0;
}
QScrollBar::handle:vertical {
    background: #3A3A3A;
    border-radius: 5px;
    min-height: 28px;
}
QScrollBar::handle:vertical:hover {
    background: #5A5A5A;
}
QScrollBar:horizontal {
    background: transparent;
    height: 10px;
    margin: 0;
}
QScrollBar::handle:horizontal {
    background: #3A3A3A;
    border-radius: 5px;
    min-width: 28px;
}
QScrollBar::handle:horizontal:hover {
    background: #5A5A5A;
}
QScrollBar::add-line, QScrollBar::sub-line {
    height: 0;
    width: 0;
    border: none;
    background: none;
}
QScrollBar::add-page, QScrollBar::sub-page {
    background: none;
}

QMenuBar {
    background-color: #101010;
    color: #E8E8E8;
    border-bottom: 1px solid #1E1E1E;
}
QMenuBar::item {
    padding: 5px 10px;
    background: transparent;
}
QMenuBar::item:selected {
    background-color: #242424;
}

QMenu {
    background-color: #161616;
    color: #E8E8E8;
    border: 1px solid #2E2E2E;
    padding: 4px;
}
QMenu::item {
    padding: 6px 22px 6px 14px;
    border-radius: 3px;
}
QMenu::item:selected {
    background-color: #E8E8E8;
    color: #0A0A0A;
}
QMenu::item:disabled {
    color: #5A5A5A;
    background-color: transparent;
}
QMenu::separator {
    height: 1px;
    background-color: #2E2E2E;
    margin: 4px 8px;
}

QGroupBox {
    border: 1px solid #1E1E1E;
    border-radius: 3px;
    margin-top: 12px;
    padding-top: 10px;
}
QGroupBox::title {
    subcontrol-origin: margin;
    subcontrol-position: top left;
    left: 10px;
    padding: 0 5px;
    color: #8A8A8A;
}

QCheckBox, QRadioButton {
    spacing: 7px;
}
QCheckBox::indicator, QRadioButton::indicator {
    width: 14px;
    height: 14px;
    background-color: #0A0A0A;
    border: 1px solid #5A5A5A;
}
QCheckBox::indicator {
    border-radius: 2px;
}
QRadioButton::indicator {
    border-radius: 7px;
}
QCheckBox::indicator:checked, QRadioButton::indicator:checked {
    background-color: #E8E8E8;
    border-color: #E8E8E8;
}

QSlider::groove:horizontal {
    height: 3px;
    background: #2E2E2E;
    border-radius: 1px;
}
QSlider::sub-page:horizontal {
    background: #E8E8E8;
    border-radius: 1px;
}
QSlider::handle:horizontal {
    background: #E8E8E8;
    width: 12px;
    height: 12px;
    margin: -5px 0;
    border-radius: 6px;
}

QProgressBar {
    background-color: #1A1A1A;
    border: 1px solid #2E2E2E;
    border-radius: 3px;
    text-align: center;
    color: #E8E8E8;
    height: 16px;
}
QProgressBar::chunk {
    background-color: #E8E8E8;
    border-radius: 2px;
}

QStatusBar {
    background-color: #101010;
    color: #8A8A8A;
    border-top: 1px solid #1E1E1E;
}
QStatusBar::item {
    border: none;
}

QSplitter::handle {
    background-color: #1E1E1E;
}
QSplitter::handle:hover {
    background-color: #3A3A3A;
}
)BNGCSS");
}
