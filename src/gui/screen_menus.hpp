// screen_menus.hpp
#pragma once
#include "ScreenFactory.hpp"

ScreenFactory::UniquePtr GetScreenMenuInfo();
ScreenFactory::UniquePtr GetScreenMenuSettings();
ScreenFactory::UniquePtr GetScreenMenuCalibration();
ScreenFactory::UniquePtr GetScreenMenuFilament();
ScreenFactory::UniquePtr GetScreenMenuTemperature();
ScreenFactory::UniquePtr GetScreenMenuMove();
ScreenFactory::UniquePtr GetScreenMenuSensorInfo();
ScreenFactory::UniquePtr GetScreenMenuVersionInfo();
ScreenFactory::UniquePtr GetScreenMenuTune();
//ScreenFactory::UniquePtr GetScreenMenuService();
ScreenFactory::UniquePtr GetScreenMenuFwUpdate();
ScreenFactory::UniquePtr GetScreenMenuLanguages();
ScreenFactory::UniquePtr GetScreenMenuLanSettings();
ScreenFactory::UniquePtr GetScreenMenuWiFi();
ScreenFactory::UniquePtr GetScreenMenuLanguagesNoRet();
ScreenFactory::UniquePtr GetScreenMenuHwSetup();
ScreenFactory::UniquePtr GetScreenMenuSteelSheets();
ScreenFactory::UniquePtr GetScreenEeprom();
