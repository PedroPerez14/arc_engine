//Header that should only be included from client applications, like Sandbox, never ARC itself.

#pragma once

#include "ARC/Application.h"
#include "ARC/Layer.h"
#include "ARC/Log.h"

// Input related stuff
#include "ARC/Input.h"
#include "ARC/KeyCodes.h"
#include "ARC/MouseButtonCodes.h"

// Interface via ImGui
#include "ARC/ImGui/ImGuiLayer.h"

// ----- ENTRY POINT GOES HERE -----
#include "ARC/EntryPoint.h"
// ---------------------------------