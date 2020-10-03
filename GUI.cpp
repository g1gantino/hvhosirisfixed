#include <fstream>
#include <functional>
#include <string>
#include <ShlObj.h>
#include <Windows.h>

#include "imgui/imgui.h"
#include "imgui/imgui_impl_win32.h"
#include "imgui/imgui_stdlib.h"

#include "imguiCustom.h"

#include "GUI.h"
#include "Config.h"
#include "Hacks/Misc.h"
#include "Hacks/SkinChanger.h"
#include "Hooks.h"
#include "Interfaces.h"
#include "SDK/InputSystem.h"

GUI::GUI() noexcept
{
    ImGui::StyleColorsDark();
    ImGuiStyle& style = ImGui::GetStyle();

    ImGuiIO& io = ImGui::GetIO();
    io.IniFilename = nullptr;
    io.LogFilename = nullptr;
    io.ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange;

    if (PWSTR pathToFonts; SUCCEEDED(SHGetKnownFolderPath(FOLDERID_Fonts, 0, nullptr, &pathToFonts))) {
        const std::filesystem::path path{ pathToFonts };
        CoTaskMemFree(pathToFonts);

        static constexpr ImWchar ranges[]{ 0x0020, 0xFFFF, 0 };
        ImFontConfig cfg;
        cfg.OversampleV = 3;

        fonts.tahoma = io.Fonts->AddFontFromFileTTF((path / "tahoma.ttf").string().c_str(), 15.0f, &cfg, ranges);
        fonts.tahoma34 = io.Fonts->AddFontFromFileTTF((path / "tahoma.ttf").string().c_str(), 34.0f, &cfg, ranges);
        fonts.segoeui = io.Fonts->AddFontFromFileTTF((path / "segoeui.ttf").string().c_str(), 15.0f, &cfg, ranges);
    }
}

void GUI::render() noexcept
{

    if (!config->style.menuStyle) {
        
        renderNewGui();

    }
    else {

        renderGui();

    }
}

void GUI::hotkey(int& key) noexcept
{
    key ? ImGui::Text("[ %s ]", interfaces->inputSystem->virtualKeyToString(key)) : ImGui::TextUnformatted("[ key ]");

    if (!ImGui::IsItemHovered())
        return;

    ImGui::SetTooltip("press any key to continue");
    ImGuiIO& io = ImGui::GetIO();
    for (int i = 0; i < IM_ARRAYSIZE(io.KeysDown); i++)
        if (ImGui::IsKeyPressed(i) && i != config->misc.menuKey)
            key = i != VK_ESCAPE ? i : 0;

    for (int i = 0; i < IM_ARRAYSIZE(io.MouseDown); i++)
        if (ImGui::IsMouseDown(i) && i + (i > 1 ? 2 : 1) != config->misc.menuKey)
            key = i + (i > 1 ? 2 : 1);
}

void GUI::renderLegitbotWindow() noexcept
{
    static int currentCategory{ 0 };
    ImGui::PushItemWidth(110.0f);
    ImGui::PushID(0);
    ImGui::Combo("", &currentCategory, "General\0Pistol\0Rifle\0AWP\0Scout\0SMG");
    ImGui::PopID();
    ImGui::SameLine();
    static int currentWeapon{ 0 };
    ImGui::PushID(1);

    switch (currentCategory) {
    case 0:
        currentWeapon = 0;
        break;
    case 1:
        currentWeapon = 35;
        break;
    case 2:
        currentWeapon = 36;
        break;
    case 3:
        currentWeapon = 37;
        break;
    case 4:
        currentWeapon = 38;
        break;
    case 5:
        currentWeapon = 39;
        break;
    }
    ImGui::PopID();
    ImGui::SameLine();
    ImGui::Checkbox("enabled", &config->legitbot[currentWeapon].enabled);
    ImGui::Separator();
    ImGui::Columns(2, nullptr, false);
    ImGui::SetColumnOffset(1, 220.0f);
    ImGui::Checkbox("on key", &config->legitbot[currentWeapon].onKey);
    ImGui::SameLine();
    hotkey(config->legitbot[currentWeapon].key);
    ImGui::SameLine();
    ImGui::PushID(2);
    ImGui::PushItemWidth(70.0f);
    ImGui::Combo("", &config->legitbot[currentWeapon].keyMode, "Hold\0Toggle\0");
    ImGui::PopItemWidth();
    ImGui::PopID();
    ImGui::Checkbox("aimlock", &config->legitbot[currentWeapon].aimlock);
    ImGui::Checkbox("silent", &config->legitbot[currentWeapon].silent);
    ImGui::Checkbox("friendly fire", &config->legitbot[currentWeapon].friendlyFire);
    ImGui::Checkbox("scoped only", &config->legitbot[currentWeapon].scopedOnly);
    ImGui::Checkbox("ignore flash", &config->legitbot[currentWeapon].ignoreFlash);
    ImGui::Checkbox("ignore smoke", &config->legitbot[currentWeapon].ignoreSmoke);
    static const char* hitboxes[]{ "Head","Chest","Stomach","Arms","Legs" };
    static std::string previewvalue = "";
    if (ImGui::BeginCombo("hitbox", previewvalue.c_str()))
    {
        previewvalue = "";
        for (size_t i = 0; i < ARRAYSIZE(hitboxes); i++)
        {
            ImGui::Selectable(hitboxes[i], &config->legitbot[currentWeapon].hitboxes[i], ImGuiSelectableFlags_::ImGuiSelectableFlags_DontClosePopups);
        }
        ImGui::EndCombo();
    }
    bool once = false;
    for (size_t i = 0; i < ARRAYSIZE(hitboxes); i++)
    {
        if (!once)
        {
            previewvalue = "";
            once = true;
        }
        if (config->legitbot[currentWeapon].hitboxes[i])
        {
            previewvalue += previewvalue.size() ? std::string(", ") + hitboxes[i] : hitboxes[i];
        }
    }
    ImGui::NextColumn();
    ImGui::PushItemWidth(240.0f);
    ImGui::SliderFloat("fov", &config->legitbot[currentWeapon].fov, 0.0f, 255.0f, "%.2f", 2.5f);
    ImGui::SliderFloat("smooth", &config->legitbot[currentWeapon].smooth, 1.0f, 100.0f, "%.2f");
    ImGui::SliderInt("reaction Time", &config->legitbot[currentWeapon].reactionTime, 0, 300, "%d");
    ImGui::SliderInt("multipoint", &config->legitbot[currentWeapon].multipoint, 0, 100, "%d");
    ImGui::Checkbox("aim at backtrack", &config->legitbot[currentWeapon].backtrack);
    ImGui::Columns(1);
}

void GUI::renderRagebotWindow() noexcept
{
    static int currentCategory{ 0 };
    ImGui::PushItemWidth(110.0f);
    ImGui::PushID(0);
    ImGui::Combo("", &currentCategory, "General\0Pistol\0Heavy Pistol\0Scout\0AWP\0Autosniper");
    ImGui::PopID();
    ImGui::SameLine();
    static int currentWeapon{ 0 };
    ImGui::PushID(1);

    switch (currentCategory) {
    case 0:
        currentWeapon = 0;
        break;
    case 1:
        currentWeapon = 35;
        break;
    case 2:
        currentWeapon = 36;
        break;
    case 3:
        currentWeapon = 37;
        break;
    case 4:
        currentWeapon = 38;
        break;
    case 5:
        currentWeapon = 39;
        break;
    }
    ImGui::PopID();
    ImGui::SameLine();
    ImGui::Checkbox("enabled", &config->ragebot[currentWeapon].enabled);
    ImGui::Separator();
    ImGui::Columns(2, nullptr, false);
    ImGui::SetColumnOffset(1, 220.0f);
    ImGui::Checkbox("on key", &config->ragebot[currentWeapon].onKey);
    ImGui::SameLine();
    hotkey(config->ragebot[currentWeapon].key);
    ImGui::SameLine();
    ImGui::PushID(2);
    ImGui::PushItemWidth(70.0f);
    ImGui::Combo("", &config->ragebot[currentWeapon].keyMode, "Hold\0Toggle\0");
    ImGui::PopItemWidth();
    ImGui::PopID();
    ImGui::Checkbox("silent", &config->ragebot[currentWeapon].silent);
    ImGui::Checkbox("friendly fire", &config->ragebot[currentWeapon].friendlyFire);
    ImGui::Checkbox("visible only", &config->ragebot[currentWeapon].visibleOnly);
    ImGui::Checkbox("scoped only", &config->ragebot[currentWeapon].scopedOnly);
    ImGui::Checkbox("ignore flash", &config->ragebot[currentWeapon].ignoreFlash);
    ImGui::Checkbox("ignore smoke", &config->ragebot[currentWeapon].ignoreSmoke);
    ImGui::Checkbox("auto shot", &config->ragebot[currentWeapon].autoShot);
    ImGui::Checkbox("auto scope", &config->ragebot[currentWeapon].autoScope);
    ImGui::Checkbox("auto stop", &config->ragebot[currentWeapon].autoStop);
    ImGui::SameLine();
    ImGui::Checkbox("between Shots", &config->ragebot[currentWeapon].betweenShots);
    ImGui::Combo("priority", &config->ragebot[currentWeapon].priority, "Health\0Distance\0Fov\0");
    static const char* hitboxes[]{ "Head","Chest","Stomach","Arms","Legs" };
    static std::string previewvalue = "";
    if (ImGui::BeginCombo("Hitbox", previewvalue.c_str()))
    {
        previewvalue = "";
        for (size_t i = 0; i < ARRAYSIZE(hitboxes); i++)
        {
            ImGui::Selectable(hitboxes[i], &config->ragebot[currentWeapon].hitboxes[i], ImGuiSelectableFlags_::ImGuiSelectableFlags_DontClosePopups);
        }
        ImGui::EndCombo();
    }
    bool once = false;
    for (size_t i = 0; i < ARRAYSIZE(hitboxes); i++)
    {
        if (!once)
        {
            previewvalue = "";
            once = true;
        }
        if (config->ragebot[currentWeapon].hitboxes[i])
        {
            previewvalue += previewvalue.size() ? std::string(", ") + hitboxes[i] : hitboxes[i];
        }
    }
    ImGui::NextColumn();
    ImGui::PushItemWidth(240.0f);
    ImGui::SliderFloat("fov", &config->ragebot[currentWeapon].fov, 0.0f, 255.0f, "%.2f", 2.5f);
    ImGui::SliderInt("hitchance", &config->ragebot[currentWeapon].hitChance, 0, 100, "%d");
    ImGui::SliderInt("multipoint", &config->ragebot[currentWeapon].multiPoint, 0, 100, "%d");
    ImGui::SliderInt("min damage", &config->ragebot[currentWeapon].minDamage, 0, 250, "%d");
    std::clamp(config->ragebot[currentWeapon].minDamage, 0, 250);
    ImGui::Separator();
    ImGui::Text("override min damage key");
    ImGui::SameLine();
    hotkey(config->ragebot[currentWeapon].overrideDamageKey);
    ImGui::Separator();
    ImGui::SliderInt("overriden min damage", &config->ragebot[currentWeapon].overrideDamageAmount, 0, 250, "%d");
    std::clamp(config->ragebot[currentWeapon].overrideDamageAmount, 0, 250);
    ImGui::Separator();
    ImGui::Text("body aim key");
    ImGui::SameLine();
    hotkey(config->ragebot[currentWeapon].bodyAimKey);
    ImGui::Text("_________________");
    ImGui::Checkbox("basic resolver", &config->ragebotExtra.resolver);
    ImGui::Separator();
    ImGui::Checkbox("exploits", &config->ragebotExtra.enabled);
    ImGui::Checkbox("doubletap, not working yet", &config->ragebotExtra.doubletap);
    ImGui::Combo("doubletap speed", &config->ragebotExtra.doubletapSpeed, "Instant\0Fast\0Accurate\0");
    ImGui::Columns(1);
}

void GUI::renderAntiAimWindow() noexcept
{
    ImGui::Checkbox("enabled", &config->antiAim.enabled);
    ImGui::Combo("mode", &config->antiAim.mode, "Legit\0Rage\0");
    ImGui::Combo("lby delta", &config->antiAim.lbyDelta, "Minimum\0Maximum\0");
    if (config->antiAim.mode == 1) {
        ImGui::Combo("pitch angle", &config->antiAim.pitchAngle, "Viewangles\0Down\0Zero\0Up\0");
        ImGui::Combo("yaw angle", &config->antiAim.yawAngle, "Forward\0Back\0Forward jitter\0Back jitter\0Fast spin\0Slow spin\0");
        if ((config->antiAim.yawAngle == 2) || (config->antiAim.yawAngle == 3))
            ImGui::SliderInt("jitter yaw range", &config->antiAim.jitterRange, 0, 180, "%d");
    }
    ImGui::Checkbox("lby sway", &config->antiAim.lbySway);

    ImGui::Checkbox("auto direction", &config->antiAim.autodir);
    if (!config->antiAim.autodir)
    {
        ImGui::Text("invert key");
        ImGui::SameLine();
        hotkey(config->antiAim.invert);
    }

    ImGui::Separator();
   
}

void GUI::renderTriggerbotWindow() noexcept
{
    static const char* hitboxes[]{ "Head","Chest","Stomach","Arms","Legs" };
    static std::string previewvalue = "";
    bool once = false;
    static int currentCategory{ 0 };
    ImGui::PushItemWidth(110.0f);
    ImGui::PushID(0);
    ImGui::Combo("", &currentCategory, "General\0Pistol\0Rifle\0AWP\0Scout\0SMG");
    ImGui::PopID();
    ImGui::SameLine();
    static int currentWeapon{ 0 };
    ImGui::PushID(1);

    switch (currentCategory) {
    case 0:
        currentWeapon = 0;
        break;
    case 1:
        currentWeapon = 35;
        break;
    case 2:
        currentWeapon = 36;
        break;
    case 3:
        currentWeapon = 37;
        break;
    case 4:
        currentWeapon = 38;
        break;
    case 5:
        currentWeapon = 39;
        break;
    }
    ImGui::PopID();
    ImGui::SameLine();
    ImGui::Checkbox("enabled", &config->triggerbot[currentWeapon].enabled);
    ImGui::Separator();
    ImGui::Checkbox("on key", &config->triggerbot[currentWeapon].onKey);
    ImGui::SameLine();
    hotkey(config->triggerbot[currentWeapon].key);
    ImGui::Checkbox("friendly fire", &config->triggerbot[currentWeapon].friendlyFire);
    ImGui::Checkbox("scoped only", &config->triggerbot[currentWeapon].scopedOnly);
    ImGui::Checkbox("ignore flash", &config->triggerbot[currentWeapon].ignoreFlash);
    ImGui::Checkbox("ignore smoke", &config->triggerbot[currentWeapon].ignoreSmoke);
    if (ImGui::BeginCombo("hitbox", previewvalue.c_str()))
    {
        previewvalue = "";
        for (size_t i = 0; i < ARRAYSIZE(hitboxes); i++)
        {
            ImGui::Selectable(hitboxes[i], &config->triggerbot[currentWeapon].hitboxes[i], ImGuiSelectableFlags_::ImGuiSelectableFlags_DontClosePopups);
        }
        ImGui::EndCombo();
    }
    for (size_t i = 0; i < ARRAYSIZE(hitboxes); i++)
    {
        if (!once)
        {
            previewvalue = "";
            once = true;
        }
        if (config->triggerbot[currentWeapon].hitboxes[i])
        {
            previewvalue += previewvalue.size() ? std::string(", ") + hitboxes[i] : hitboxes[i];
        }
    }
    ImGui::SetNextItemWidth(85.0f);
    ImGui::PushItemWidth(220.0f);
    ImGui::SliderInt("hitchance", &config->triggerbot[currentWeapon].hitChance, 0, 100, "%d");
    ImGui::SetNextItemWidth(85.0f);
    ImGui::PushItemWidth(220.0f);
    ImGui::SliderInt("shot delay", &config->triggerbot[currentWeapon].shotDelay, 0, 250, "%d ms");
    ImGui::InputInt("min damage", &config->triggerbot[currentWeapon].minDamage);
    config->triggerbot[currentWeapon].minDamage = std::clamp(config->triggerbot[currentWeapon].minDamage, 0, 250);
    ImGui::Checkbox("killshot", &config->triggerbot[currentWeapon].killshot);
}

void GUI::renderBacktrackWindow() noexcept
{
    ImGui::Checkbox("enabled", &config->backtrack.enabled);
    ImGui::Checkbox("ignore smoke", &config->backtrack.ignoreSmoke);
    ImGui::Checkbox("ignore flash", &config->backtrack.ignoreFlash);
    ImGui::PushItemWidth(220.0f);
    ImGui::SliderInt("time limit", &config->backtrack.timeLimit, 1, 200, "%d ms");
    ImGui::PopItemWidth();
    ImGui::Checkbox("enabled fake latency", &config->backtrack.fakeLatency);
    ImGui::PushItemWidth(220.0f);
    ImGui::SliderInt("latency amount", &config->backtrack.fakeLatencyAmount, 1, 200, "%d ms");
    ImGui::PopItemWidth();
}

void GUI::renderGlowWindow() noexcept
{
    static int currentCategory{ 0 };
    ImGui::PushItemWidth(110.0f);
    ImGui::PushID(0);
    ImGui::Combo("", &currentCategory, "Allies\0Enemies\0Planting\0Defusing\0Local player\0Weapons\0C4\0Planted C4\0Chickens\0Defuse kits\0Projectiles\0Hostages\0Ragdolls\0");
    ImGui::PopID();
    static int currentItem{ 0 };
    if (currentCategory <= 3) {
        ImGui::SameLine();
        static int currentType{ 0 };
        ImGui::PushID(1);
        ImGui::Combo("", &currentType, "All\0Visible\0Occluded\0");
        ImGui::PopID();
        currentItem = currentCategory * 3 + currentType;
    } else {
        currentItem = currentCategory + 8;
    }

    ImGui::SameLine();
    ImGui::Checkbox("enabled", &config->glow[currentItem].enabled);
    ImGui::Separator();
    ImGui::Columns(2, nullptr, false);
    ImGui::SetColumnOffset(1, 150.0f);
    ImGui::Checkbox("health based", &config->glow[currentItem].healthBased);

    ImGuiCustom::colorPopup("color", config->glow[currentItem].color, &config->glow[currentItem].rainbow, &config->glow[currentItem].rainbowSpeed);

    ImGui::NextColumn();
    ImGui::SetNextItemWidth(100.0f);
    ImGui::Combo("style", &config->glow[currentItem].style, "Default\0Rim3d\0Edge\0Edge Pulse\0");
   
    ImGui::Columns(1);
}

void GUI::renderChamsWindow() noexcept
{
    static int currentCategory{ 0 };
    ImGui::PushItemWidth(110.0f);
    ImGui::PushID(0);

    static int material = 1;

    if (ImGui::Combo("", &currentCategory, "Allies\0Enemies\0Local player\0Weapons\0Hands\0Backtrack\0Sleeves\0Desync\0"))
        material = 1;

    ImGui::PopID();

    static int currentItem{ 0 };

    if (currentCategory <= 1) {
        ImGui::SameLine();
        static int currentType{ 0 };
        ImGui::PushID(1);
        if (ImGui::Combo("", &currentType, "Visible\0Occluded\0"))
            material = 1;
        ImGui::PopID();
        currentItem = currentCategory * 2 + currentType;
    }
    else {
        currentItem = currentCategory + 2;
    }

    ImGui::SameLine();

    if (material <= 1)
        ImGuiCustom::arrowButtonDisabled("##left", ImGuiDir_Left);
    else if (ImGui::ArrowButton("##left", ImGuiDir_Left))
        --material;

    ImGui::SameLine();
    ImGui::Text("%d", material);
    ImGui::SameLine();

    if (material >= int(config->chams[0].materials.size()))
        ImGuiCustom::arrowButtonDisabled("##right", ImGuiDir_Right);
    else if (ImGui::ArrowButton("##right", ImGuiDir_Right))
        ++material;

    ImGui::SameLine();
    auto& chams{ config->chams[currentItem].materials[material - 1] };

    ImGui::Checkbox("enabled", &chams.enabled);
    ImGui::Separator();
    ImGui::Checkbox("health based", &chams.healthBased);
    ImGui::Checkbox("blinking", &chams.blinking);
    ImGui::Combo("material", &chams.material, "Normal\0Flat\0Animated\0Platinum\0Glass\0Chrome\0Crystal\0Silver\0Gold\0Plastic\0Glow\0Pearlescent\0Metallic\0MetalSnow\0GlassWindow\0C4Gift\0UrbanPuddle\0CrystalCubeVertigo\0Seagull...\0Zombie\0Searchlight\0BrokenGlass\0CrystalBlue\0Velvet\0Water1\0de_vetigo/tv_news_02\0Whiteboard01\0Whiteboard04\0");
    ImGui::Checkbox("wireframe", &chams.wireframe);
    ImGuiCustom::colorPopup("color", chams.color, &chams.rainbow, &chams.rainbowSpeed);
}

void GUI::renderEspWindow() noexcept
{
    static int currentCategory = 0;
    static int currentItem = 0;

    if (ImGui::ListBoxHeader("##", { 125.0f, 300.0f })) {
        static constexpr const char* players[]{ "All", "Visible", "Occluded" };

        ImGui::Text("allies");
        ImGui::Indent();
        ImGui::PushID("allies");
        ImGui::PushFont(fonts.segoeui);

        for (int i = 0; i < IM_ARRAYSIZE(players); i++) {
            bool isSelected = currentCategory == 0 && currentItem == i;

            if ((i == 0 || !config->esp.players[0].enabled) && ImGui::Selectable(players[i], isSelected)) {
                currentItem = i;
                currentCategory = 0;
            }
        }

        ImGui::PopFont();
        ImGui::PopID();
        ImGui::Unindent();
        ImGui::Text("enemies");
        ImGui::Indent();
        ImGui::PushID("enemies");
        ImGui::PushFont(fonts.segoeui);

        for (int i = 0; i < IM_ARRAYSIZE(players); i++) {
            bool isSelected = currentCategory == 1 && currentItem == i;

            if ((i == 0 || !config->esp.players[3].enabled) && ImGui::Selectable(players[i], isSelected)) {
                currentItem = i;
                currentCategory = 1;
            }
        }

        ImGui::PopFont();
        ImGui::PopID();
        ImGui::Unindent();
        if (bool isSelected = currentCategory == 2; ImGui::Selectable("Weapons", isSelected))
            currentCategory = 2;

        ImGui::Text("projectiles");
        ImGui::Indent();
        ImGui::PushID("projectiles");
        ImGui::PushFont(fonts.segoeui);
        static constexpr const char* projectiles[]{ "Flashbang", "HE Grenade", "Breach Charge", "Bump Mine", "Decoy Grenade", "Molotov", "TA Grenade", "Smoke Grenade", "Snowball" };

        for (int i = 0; i < IM_ARRAYSIZE(projectiles); i++) {
            bool isSelected = currentCategory == 3 && currentItem == i;

            if (ImGui::Selectable(projectiles[i], isSelected)) {
                currentItem = i;
                currentCategory = 3;
            }
        }

        ImGui::PopFont();
        ImGui::PopID();
        ImGui::Unindent();

        ImGui::Text("danger zone");
        ImGui::Indent();
        ImGui::PushID("danger zone");
        ImGui::PushFont(fonts.segoeui);
        static constexpr const char* dangerZone[]{ "Sentries", "Drones", "Cash", "Cash Dufflebag", "Pistol Case", "Light Case", "Heavy Case", "Explosive Case", "Tools Case", "Full Armor", "Armor", "Helmet", "Parachute", "Briefcase", "Tablet Upgrade", "ExoJump", "Ammobox", "Radar Jammer" };

        for (int i = 0; i < IM_ARRAYSIZE(dangerZone); i++) {
            bool isSelected = currentCategory == 4 && currentItem == i;

            if (ImGui::Selectable(dangerZone[i], isSelected)) {
                currentItem = i;
                currentCategory = 4;
            }
        }

        ImGui::PopFont();
        ImGui::PopID();
        ImGui::ListBoxFooter();
    }
    ImGui::SameLine();
    if (ImGui::BeginChild("##child", { 400.0f, 0.0f })) {
        switch (currentCategory) {
        case 0:
        case 1: {
            int selected = currentCategory * 3 + currentItem;
            ImGui::Checkbox("enabled", &config->esp.players[selected].enabled);
            ImGui::SameLine(0.0f, 50.0f);
            ImGui::SetNextItemWidth(85.0f);

            ImGui::Separator();

            constexpr auto spacing{ 185.0f };
            ImGuiCustom::colorPicker("snaplines", config->esp.players[selected].snaplines);
            ImGui::SameLine(spacing);
            ImGuiCustom::colorPicker("box", config->esp.players[selected].box);
            ImGui::SameLine();
            ImGui::SetNextItemWidth(95.0f);
            ImGui::Combo("", &config->esp.players[selected].boxType, "2D\0""2D corners\0");
            ImGuiCustom::colorPicker("eye traces", config->esp.players[selected].eyeTraces);
            ImGui::SameLine(spacing);
            ImGuiCustom::colorPicker("health", config->esp.players[selected].health);
            ImGuiCustom::colorPicker("head dot", config->esp.players[selected].headDot);
            ImGui::SameLine(spacing);
            ImGui::Checkbox("health bar", &config->esp.players[selected].healthBar);
            ImGui::SameLine();
            ImGui::SetNextItemWidth(70.f);
            ImGuiCustom::colorPicker("override", config->esp.players[selected].healthBarColor);
            ImGuiCustom::colorPicker("name", config->esp.players[selected].name);
            ImGui::SameLine(spacing);
            ImGuiCustom::colorPicker("armor", config->esp.players[selected].armor);
            ImGuiCustom::colorPicker("money", config->esp.players[selected].money);
            ImGui::SameLine(spacing);
            ImGuiCustom::colorPicker("armor bar", config->esp.players[selected].armorBar);
            ImGuiCustom::colorPicker("distance", config->esp.players[selected].distance);
            ImGui::SameLine(spacing);
            ImGuiCustom::colorPicker("outline", config->esp.players[selected].outline);
            ImGuiCustom::colorPicker("active Weapon", config->esp.players[selected].activeWeapon);
            ImGui::SameLine(spacing);
            ImGui::Checkbox("dead ESP", &config->esp.players[selected].deadesp);
            ImGui::SliderFloat("max distance", &config->esp.players[selected].maxDistance, 0.0f, 200.0f, "%.2fm");
            ImGui::SetNextItemWidth(70.f);
            break;
        }
        case 2: {
            ImGui::Checkbox("enabled", &config->esp.weapon.enabled);
            ImGui::SameLine(0.0f, 50.0f);
            ImGui::SetNextItemWidth(85.0f);

            ImGui::Separator();

            constexpr auto spacing{ 200.0f };
            ImGuiCustom::colorPicker("snaplines", config->esp.weapon.snaplines);
            ImGui::SameLine(spacing);
            ImGuiCustom::colorPicker("box", config->esp.weapon.box);
            ImGui::SameLine();
            ImGui::SetNextItemWidth(95.0f);
            ImGui::Combo("", &config->esp.weapon.boxType, "2D\0""2D corners\0");
            ImGuiCustom::colorPicker("name", config->esp.weapon.name);
            ImGui::SameLine(spacing);
            ImGuiCustom::colorPicker("ammo", config->esp.weapon.ammo);
            ImGuiCustom::colorPicker("outline", config->esp.weapon.outline);
            ImGuiCustom::colorPicker("distance", config->esp.weapon.distance);
            ImGui::SliderFloat("max distance", &config->esp.weapon.maxDistance, 0.0f, 200.0f, "%.2fm");
            break;
        }
        case 3: {
            ImGui::Checkbox("enabled", &config->esp.projectiles[currentItem].enabled);
            ImGui::SameLine(0.0f, 50.0f);
            ImGui::SetNextItemWidth(85.0f);

            ImGui::Separator();

            constexpr auto spacing{ 200.0f };
            ImGuiCustom::colorPicker("snaplines", config->esp.projectiles[currentItem].snaplines);
            ImGui::SameLine(spacing);
            ImGuiCustom::colorPicker("box", config->esp.projectiles[currentItem].box);
            ImGui::SameLine();
            ImGui::SetNextItemWidth(95.0f);
            ImGui::Combo("", &config->esp.projectiles[currentItem].boxType, "2D\0""2D corners\0");
            ImGuiCustom::colorPicker("name", config->esp.projectiles[currentItem].name);
            ImGui::SameLine(spacing);
            ImGuiCustom::colorPicker("outline", config->esp.projectiles[currentItem].outline);
            ImGuiCustom::colorPicker("distance", config->esp.projectiles[currentItem].distance);
            ImGui::SliderFloat("max distance", &config->esp.projectiles[currentItem].maxDistance, 0.0f, 200.0f, "%.2fm");
            break;
        }
        case 4: {
            int selected = currentItem;
            ImGui::Checkbox("enabled", &config->esp.dangerZone[selected].enabled);
            ImGui::SameLine(0.0f, 50.0f);
            ImGui::SetNextItemWidth(85.0f);

            ImGui::Separator();

            constexpr auto spacing{ 200.0f };
            ImGuiCustom::colorPicker("snaplines", config->esp.dangerZone[selected].snaplines);
            ImGui::SameLine(spacing);
            ImGuiCustom::colorPicker("box", config->esp.dangerZone[selected].box);
            ImGui::SameLine();
            ImGui::SetNextItemWidth(95.0f);
            ImGui::Combo("", &config->esp.dangerZone[selected].boxType, "2D\0""2D corners\0");
            ImGuiCustom::colorPicker("name", config->esp.dangerZone[selected].name);
            ImGui::SameLine(spacing);
            ImGuiCustom::colorPicker("outline", config->esp.dangerZone[selected].outline);
            ImGuiCustom::colorPicker("distance", config->esp.dangerZone[selected].distance);
            ImGui::SliderFloat("max distance", &config->esp.dangerZone[selected].maxDistance, 0.0f, 200.0f, "%.2fm");
            break;
        }
        }

        ImGui::EndChild();
    }
}

void GUI::renderVisualsWindow() noexcept
{
    ImGui::Columns(2, nullptr, false);
    ImGui::SetColumnOffset(1, 280.0f);
    constexpr auto playerModels = "Default\0Special Agent Ava | FBI\0Operator | FBI SWAT\0Markus Delrow | FBI HRT\0Michael Syfers | FBI Sniper\0B Squadron Officer | SAS\0Seal Team 6 Soldier | NSWC SEAL\0Buckshot | NSWC SEAL\0Lt. Commander Ricksaw | NSWC SEAL\0Third Commando Company | KSK\0'Two Times' McCoy | USAF TACP\0Dragomir | Sabre\0Rezan The Ready | Sabre\0'The Doctor' Romanov | Sabre\0Maximus | Sabre\0Blackwolf | Sabre\0The Elite Mr. Muhlik | Elite Crew\0Ground Rebel | Elite Crew\0Osiris | Elite Crew\0Prof. Shahmat | Elite Crew\0Enforcer | Phoenix\0Slingshot | Phoenix\0Soldier | Phoenix\0Pirate\0Pirate Variant A\0Pirate Variant B\0Pirate Variant C\0Pirate Variant D\0Anarchist\0Anarchist Variant A\0Anarchist Variant B\0Anarchist Variant C\0Anarchist Variant D\0Balkan Variant A\0Balkan Variant B\0Balkan Variant C\0Balkan Variant D\0Balkan Variant E\0Jumpsuit Variant A\0Jumpsuit Variant B\0Jumpsuit Variant C\0";
    ImGui::Combo("t model", &config->visuals.playerModelT, playerModels);
    ImGui::Combo("ct model", &config->visuals.playerModelCT, playerModels);
    ImGui::Checkbox("disable post-processing", &config->visuals.disablePostProcessing);
    ImGui::Checkbox("inverse ragdoll gravity", &config->visuals.inverseRagdollGravity);
    ImGui::Checkbox("wireframe smoke", &config->visuals.wireframeSmoke);
    ImGui::Checkbox("penetration Crosshair", &config->visuals.PenetrationCrosshair);
    ImGui::Checkbox("deagle spinner", &config->visuals.deagleSpinner);
    ImGui::Checkbox("hitmarker", &config->visuals.hitMarker);
    ImGuiCustom::colorPicker("local bullet tracers", config->visuals.bulletTracersLocal);
    ImGuiCustom::colorPicker("teammmate bullet tracers", config->visuals.bulletTracersAllies);
    ImGuiCustom::colorPicker("enemy bullet tracers", config->visuals.bulletTracersEnemy);
    ImGui::Checkbox("color correction", &config->visuals.colorCorrection.enabled);
    ImGui::SameLine();
    bool ccPopup = ImGui::Button("Edit");
    ImGui::NextColumn();
    ImGui::SliderFloat("##Custom Viewmodel X", &config->misc.viewmodel_x, -10, 10, "Custom Viewmodel X: %.2f");
    ImGui::SliderFloat("##Custom Viewmodel Y", &config->misc.viewmodel_y, -10, 10, "Custom Viewmodel Y: %.2f");
    ImGui::SliderFloat("##Custom Viewmodel Z", &config->misc.viewmodel_z, -10, 10, "Custom Viewmodel Z: %.2f");
    if (ImGui::Button("update"))
        Misc::customViewmodel();
    ImGui::Checkbox("thirdperson", &config->visuals.thirdperson);
    ImGui::SameLine();
    hotkey(config->visuals.thirdpersonKey);
    ImGui::PushItemWidth(290.0f);
    ImGui::PushID(0);
    ImGui::SliderInt("", &config->visuals.thirdpersonDistance, 0, 1000, "thirdperson distance: %d");
    ImGui::PopID();
    ImGui::PushID(1);
    ImGui::SliderInt("", &config->visuals.thirdpersonTransparency, 0, 100, "scope transparency: %d%%");
    ImGui::PopID();
    ImGui::PushID(2);
    ImGui::SliderInt("", &config->visuals.viewmodelFov, -60, 60, "viewmodel FOV: %d");
    ImGui::PopID();
    ImGui::PushID(3);
    ImGui::SliderInt("", &config->visuals.fov, -60, 60, "fov: %d");
    ImGui::PopID();
    ImGui::PushID(4);
    ImGui::SliderInt("", &config->visuals.fovScoped, -60, 60, "scope fov: %d");
    ImGui::PopID();
    ImGui::PushID(5);
    ImGui::PopID();
    ImGui::PushID(6);
    ImGui::SliderInt("", &config->visuals.flashReduction, 0, 100, "flash reduction: %d%%");
    ImGui::PopID();
    ImGui::PushID(7);
    ImGui::SliderFloat("", &config->visuals.brightness, 0.0f, 1.0f, "brightness: %.2f");
    ImGui::PopID();
    ImGui::PopItemWidth();
    ImGui::Combo("skybox", &config->visuals.skybox, "Default\0cs_baggage_skybox_\0cs_tibet\0embassy\0italy\0jungle\0nukeblank\0office\0sky_cs15_daylight01_hdr\0sky_cs15_daylight02_hdr\0sky_cs15_daylight03_hdr\0sky_cs15_daylight04_hdr\0sky_csgo_cloudy01\0sky_csgo_night_flat\0sky_csgo_night02\0sky_day02_05_hdr\0sky_day02_05\0sky_dust\0sky_l4d_rural02_ldr\0sky_venice\0vertigo_hdr\0vertigo\0vertigoblue_hdr\0vietnam\0");
    ImGui::Checkbox("nightmode", &config->visuals.nightMode);
    ImGuiCustom::colorPicker("nightmode override", config->visuals.nightModeOverride);
    ImGui::PushID(8);
    ImGui::SliderInt("", &config->visuals.asusWalls, 0, 100, "asus walls: %d%%");
    ImGui::PopID();
    ImGui::PushID(9);
    ImGui::SliderInt("", &config->visuals.asusProps, 0, 100, "asus props: %d%%");
    ImGui::PopID();


    if (ccPopup)
        ImGui::OpenPopup("##popup");

    if (ImGui::BeginPopup("##popup")) {
        ImGui::VSliderFloat("##1", { 40.0f, 160.0f }, &config->visuals.colorCorrection.blue, 0.0f, 1.0f, "Blue\n%.3f"); ImGui::SameLine();
        ImGui::VSliderFloat("##2", { 40.0f, 160.0f }, &config->visuals.colorCorrection.red, 0.0f, 1.0f, "Red\n%.3f"); ImGui::SameLine();
        ImGui::VSliderFloat("##3", { 40.0f, 160.0f }, &config->visuals.colorCorrection.mono, 0.0f, 1.0f, "Mono\n%.3f"); ImGui::SameLine();
        ImGui::VSliderFloat("##4", { 40.0f, 160.0f }, &config->visuals.colorCorrection.saturation, 0.0f, 1.0f, "Sat\n%.3f"); ImGui::SameLine();
        ImGui::VSliderFloat("##5", { 40.0f, 160.0f }, &config->visuals.colorCorrection.ghost, 0.0f, 1.0f, "Ghost\n%.3f"); ImGui::SameLine();
        ImGui::VSliderFloat("##6", { 40.0f, 160.0f }, &config->visuals.colorCorrection.green, 0.0f, 1.0f, "Green\n%.3f"); ImGui::SameLine();
        ImGui::VSliderFloat("##7", { 40.0f, 160.0f }, &config->visuals.colorCorrection.yellow, 0.0f, 1.0f, "Yellow\n%.3f"); ImGui::SameLine();
        ImGui::EndPopup();
    }
    ImGui::Columns(1);
}

void GUI::renderSkinChangerWindow() noexcept
{
    static auto itemIndex = 0;

    ImGui::PushItemWidth(110.0f);
    ImGui::Combo("##1", &itemIndex, [](void* data, int idx, const char** out_text) {
        *out_text = game_data::weapon_names[idx].name;
        return true;
        }, nullptr, IM_ARRAYSIZE(game_data::weapon_names), 5);
    ImGui::PopItemWidth();

    auto& selected_entry = config->skinChanger[itemIndex];
    selected_entry.itemIdIndex = itemIndex;

    {
        ImGui::SameLine();
        ImGui::Checkbox("enabled", &selected_entry.enabled);
        ImGui::Separator();
        ImGui::Columns(2, nullptr, false);
        ImGui::SetColumnOffset(1, 300.0f);
        ImGui::InputInt("seed", &selected_entry.seed);
        ImGui::InputInt("stattrak\u2122", &selected_entry.stat_trak);
        selected_entry.stat_trak = (std::max)(selected_entry.stat_trak, -1);
        ImGui::SliderFloat("wear", &selected_entry.wear, FLT_MIN, 1.f, "%.10f", 5);

        static ImGuiTextFilter filter;
        filter.Draw();

        if (ImGui::ListBoxHeader("paint kit")) {
            for (size_t i = 0; i < (itemIndex == 1 ? SkinChanger::gloveKits : SkinChanger::skinKits).size(); ++i) {
                if (filter.PassFilter((itemIndex == 1 ? SkinChanger::gloveKits : SkinChanger::skinKits)[i].name.c_str()))
                    if (ImGui::Selectable((itemIndex == 1 ? SkinChanger::gloveKits : SkinChanger::skinKits)[i].name.c_str(), i == selected_entry.paint_kit_vector_index))
                        selected_entry.paint_kit_vector_index = i;
            }

            ImGui::ListBoxFooter();
        }

        ImGui::Combo("quality", &selected_entry.entity_quality_vector_index, [](void* data, int idx, const char** out_text) {
            *out_text = game_data::quality_names[idx].name;
            return true;
            }, nullptr, IM_ARRAYSIZE(game_data::quality_names), 5);

        if (itemIndex == 0) {
            ImGui::Combo("knife", &selected_entry.definition_override_vector_index, [](void* data, int idx, const char** out_text) {
                *out_text = game_data::knife_names[idx].name;
                return true;
                }, nullptr, IM_ARRAYSIZE(game_data::knife_names), 5);
        } else if (itemIndex == 1) {
            ImGui::Combo("glove", &selected_entry.definition_override_vector_index, [](void* data, int idx, const char** out_text) {
                *out_text = game_data::glove_names[idx].name;
                return true;
                }, nullptr, IM_ARRAYSIZE(game_data::glove_names), 5);
        } else {
            static auto unused_value = 0;
            selected_entry.definition_override_vector_index = 0;
            ImGui::Combo("unavailable", &unused_value, "For knives or gloves\0");
        }

        ImGui::InputText("name Tag", selected_entry.custom_name, 32);
    }

    ImGui::NextColumn();

    {
        ImGui::PushID("sticker");

        static auto selectedStickerSlot = 0;

        ImGui::PushItemWidth(-1);

        if (ImGui::ListBoxHeader("", 5)) {
            for (int i = 0; i < 5; ++i) {
                ImGui::PushID(i);

                const auto kit_vector_index = config->skinChanger[itemIndex].stickers[i].kit_vector_index;
                const std::string text = '#' + std::to_string(i + 1) + "  " + SkinChanger::stickerKits[kit_vector_index].name;

                if (ImGui::Selectable(text.c_str(), i == selectedStickerSlot))
                    selectedStickerSlot = i;

                ImGui::PopID();
            }
            ImGui::ListBoxFooter();
        }

        ImGui::PopItemWidth();

        auto& selected_sticker = selected_entry.stickers[selectedStickerSlot];

        ImGui::Combo("sticker Kit", &selected_sticker.kit_vector_index, [](void* data, int idx, const char** out_text) {
            *out_text = SkinChanger::stickerKits[idx].name.c_str();
            return true;
            }, nullptr, SkinChanger::stickerKits.size(), 10);

        ImGui::SliderFloat("wear", &selected_sticker.wear, FLT_MIN, 1.0f, "%.10f", 5.0f);
        ImGui::SliderFloat("scale", &selected_sticker.scale, 0.1f, 5.0f);
        ImGui::SliderFloat("rotation", &selected_sticker.rotation, 0.0f, 360.0f);

        ImGui::PopID();
    }
    selected_entry.update();

    ImGui::Columns(1);

    if (ImGui::Button("update", { 130.0f, 30.0f }))
        SkinChanger::scheduleHudUpdate();
}

void GUI::renderSoundWindow() noexcept
{
    //ImGui::SliderInt("Chicken volume", &config->sound.chickenVolume, 0, 200, "%d%%");
    static int currentCategory{ 0 };
    /*
    ImGui::PushItemWidth(110.0f);
    ImGui::Combo("", &currentCategory, "Local player\0Allies\0Enemies\0");
    ImGui::PopItemWidth();
    */
    ImGui::SliderInt("master volume", &config->sound.players[currentCategory].masterVolume, 0, 200, "%d%%");
    ImGui::SliderInt("headshot volume", &config->sound.players[currentCategory].headshotVolume, 0, 200, "%d%%");
    ImGui::SliderInt("weapon volume", &config->sound.players[currentCategory].weaponVolume, 0, 200, "%d%%");
    ImGui::SliderInt("footstep volume", &config->sound.players[currentCategory].footstepVolume, 0, 200, "%d%%");

    
}

void GUI::renderMiscWindow() noexcept
{
    ImGui::Columns(2, nullptr, false);
    ImGui::SetColumnOffset(1, 230.0f);
    

    ImGui::Checkbox("Draw Fov", &config->misc.drawFov);
    ImGui::Checkbox("only dev window", &config->misc.debugwindow);
    ImGui::Checkbox("left hand knife", &config->misc.oppositeHandKnife);
    ImGui::Checkbox("accurate walk", &config->misc.fastStop);
    ImGui::Checkbox("slide", &config->misc.moonwalk);
    ImGui::Checkbox("crosshair override", &config->misc.sniperCrosshair);
    ImGui::Checkbox("recoil crosshair", &config->misc.recoilCrosshair);
    ImGui::Checkbox("auto pistol fire", &config->misc.autoPistol);
    ImGui::Checkbox("auto accept", &config->misc.autoAccept);
    ImGui::Checkbox("engine radar", &config->misc.radarHack);
    ImGui::Checkbox("reveal ranks", &config->misc.revealRanks);
    ImGui::Checkbox("reveal suspect", &config->misc.revealSuspect);
    ImGui::Checkbox("spectator list", &config->misc.spectatorList);
    ImGui::Checkbox("watermark", &config->misc.watermark);
    ImGui::Checkbox("disable model occlusion", &config->misc.disableModelOcclusion);
    ImGui::SliderFloat("aspect ratio", &config->misc.aspectratio, 0.0f, 5.0f, "%.2f");
    ImGui::NextColumn();
    ImGui::Checkbox("diamondware clantag", &config->misc.gamesenseTag);
    ImGui::Checkbox("killsay", &config->misc.killSay);
    ImGui::Checkbox("chicken deathsay", &config->misc.chickenDeathSay);
    ImGui::Checkbox("steal names", &config->misc.nameStealer);
    ImGui::PushID(1);
    ImGui::SetNextItemWidth(100.0f);
    ImGui::Combo("", &config->misc.banColor, "White\0Red\0Purple\0Green\0Light green\0Turquoise\0Light red\0Gray\0Yellow\0Gray 2\0Light blue\0Gray/Purple\0Blue\0Pink\0Dark orange\0Orange\0");
    ImGui::PopID();
    ImGui::SameLine();
    ImGui::PushID(2);
    ImGui::InputText("", &config->misc.banText);
    ImGui::PopID();
    ImGui::SameLine();
    if (ImGui::Button("setup fake ban"))
        Misc::fakeBan(true);
    ImGuiCustom::colorPicker("bomb info", config->misc.bombTimer);
    ImGui::Checkbox("auto revolver", &config->misc.prepareRevolver);
    ImGui::SameLine();
    hotkey(config->misc.prepareRevolverKey);
    ImGui::Combo("hit sound", &config->misc.hitSound, "None\0Metal\0Gamesense\0Bell\0Glass\0Custom\0");
    if (config->misc.hitSound == 5) {
        ImGui::InputText("Hit Sound filename", &config->misc.customHitSound);
        if (ImGui::IsItemHovered())
            ImGui::SetTooltip("audio file must be put in csgo/sound/ directory");
    }
    ImGui::PushID(3);
    ImGui::Combo("kill sound", &config->misc.killSound, "None\0Metal\0Gamesense\0Bell\0Glass\0Custom\0");
    if (config->misc.killSound == 5) {
        ImGui::InputText("Kill Sound filename", &config->misc.customKillSound);
        if (ImGui::IsItemHovered())
            ImGui::SetTooltip("audio file must be put in csgo/sound/ directory");
    }
    ImGui::PopID();
    ImGui::Checkbox("grenade prediction", &config->misc.nadePredict);
    ImGui::Checkbox("grenade trajectory", &config->misc.nadeTrajectory);
    ImGui::Checkbox("show impacts", &config->misc.showImpacts);
    ImGui::SetNextItemWidth(120.0f);
    ImGui::SliderFloat("max angle delta", &config->misc.maxAngleDelta, 0.0f, 255.0f, "%.2f");
    ImGui::Checkbox("fake prime", &config->misc.fakePrime);
    ImGui::Checkbox("unlock inventory", &config->misc.unlockInventory);
    ImGui::Checkbox("bypass sv pure", &config->misc.svpurebypass);
    ImGui::Checkbox("preserve killfeed", &config->misc.preserveDeathNotices);
    ImGui::Checkbox("auto disconnect", &config->misc.autoDisconnect);
    ImGui::Checkbox("purchase List", &config->misc.purchaseList.enabled);
    ImGui::SameLine();

    ImGui::PushID("purchase List");
    if (ImGui::Button("..."))
        ImGui::OpenPopup("");

    if (ImGui::BeginPopup("")) {
        ImGui::SetNextItemWidth(75.0f);
        ImGui::Combo("mode", &config->misc.purchaseList.mode, "Details\0Summary\0");
        ImGui::Checkbox("only during freeze time", &config->misc.purchaseList.onlyDuringFreezeTime);
        ImGui::Checkbox("show prices", &config->misc.purchaseList.showPrices);
        ImGui::Checkbox("no Title Bar", &config->misc.purchaseList.noTitleBar);
        ImGui::EndPopup();
    }
    ImGui::PopID();

    ImGui::Checkbox("autobuy", &config->misc.autoBuy.enabled);
    ImGui::SameLine();

    ImGui::PushID("autobuy");
    if (ImGui::Button("..."))
        ImGui::OpenPopup("");

    if (ImGui::BeginPopup("")) {
        ImGui::Combo("primary weapon", &config->misc.autoBuy.primaryWeapon, "None\0MAC-10 | MP9\0MP7 | MP5-SD\0UMP-45\0P90\0PP-Bizon\0Galil AR | FAMAS\0AK-47 | M4A4 | M4A1-S\0SSG 08\0SG553 |AUG\0AWP\0G3SG1 | SCAR-20\0Nova\0XM1014\0Sawed-Off | MAG-7\0M249\0Negev\0");
        ImGui::Combo("secondary weapon", &config->misc.autoBuy.secondaryWeapon, "None\0Glock-18 | P2000 | USP-S\0Dual Berettas\0P250\0CZ75-Auto | Five-SeveN | Tec-9\0Desert Eagle | R8 Revolver\0");
        ImGui::Combo("armor", &config->misc.autoBuy.armor, "None\0Kevlar\0Kevlar + Helmet\0");

        static const char* utility[]{ "Defuser","Taser" };
        static std::string previewvalueutility = "";
        if (ImGui::BeginCombo("Utility", previewvalueutility.c_str()))
        {
            previewvalueutility = "";
            for (size_t i = 0; i < ARRAYSIZE(utility); i++)
            {
                ImGui::Selectable(utility[i], &config->misc.autoBuy.utility[i], ImGuiSelectableFlags_::ImGuiSelectableFlags_DontClosePopups);
            }
            ImGui::EndCombo();
        }
        bool onceUtility = false;
        for (size_t i = 0; i < ARRAYSIZE(utility); i++)
        {
            if (!onceUtility)
            {
                previewvalueutility = "";
                onceUtility = true;
            }
            if (config->misc.autoBuy.utility[i])
            {
                previewvalueutility += previewvalueutility.size() ? std::string(", ") + utility[i] : utility[i];
            }
        }

        static const char* nades[]{ "HE Grenade","Smoke Grenade","Molotov","Flashbang","Decoy" };
        static std::string previewvaluenades = "";
        if (ImGui::BeginCombo("grenades", previewvaluenades.c_str()))
        {
            previewvaluenades = "";
            for (size_t i = 0; i < ARRAYSIZE(nades); i++)
            {
                ImGui::Selectable(nades[i], &config->misc.autoBuy.grenades[i], ImGuiSelectableFlags_::ImGuiSelectableFlags_DontClosePopups);
            }
            ImGui::EndCombo();
        }
        bool onceNades = false;
        for (size_t i = 0; i < ARRAYSIZE(nades); i++)
        {
            if (!onceNades)
            {
                previewvaluenades = "";
                onceNades = true;
            }
            if (config->misc.autoBuy.grenades[i])
            {
                previewvaluenades += previewvaluenades.size() ? std::string(", ") + nades[i] : nades[i];
            }
        }
        ImGui::EndPopup();
    }
    ImGui::PopID();

 

    ImGui::Columns(1);
}

void GUI::renderConfigWindow() noexcept
{
    ImGui::Columns(2, nullptr, false);
    ImGui::SetColumnOffset(1, 170.0f);

    ImGui::PushItemWidth(160.0f);

    if (ImGui::Button("reload configs", { 160.0f, 25.0f }))
        config->listConfigs();

    auto& configItems = config->getConfigs();
    static int currentConfig = -1;

    if (static_cast<std::size_t>(currentConfig) >= configItems.size())
        currentConfig = -1;

    static std::string buffer;

    if (ImGui::ListBox("", &currentConfig, [](void* data, int idx, const char** out_text) {
        auto& vector = *static_cast<std::vector<std::string>*>(data);
        *out_text = vector[idx].c_str();
        return true;
        }, &configItems, configItems.size(), 5) && currentConfig != -1)
            buffer = configItems[currentConfig];

        ImGui::PushID(0);
        if (ImGui::InputTextWithHint("", "config name", &buffer, ImGuiInputTextFlags_EnterReturnsTrue)) {
            if (currentConfig != -1)
                config->rename(currentConfig, buffer.c_str());
        }
        ImGui::PopID();
        ImGui::NextColumn();

        ImGui::PushItemWidth(100.0f);

        if (ImGui::Button("create config", { 100.0f, 25.0f }))
            config->add(buffer.c_str());

        if (ImGui::Button("reset config", { 100.0f, 25.0f }))
            ImGui::OpenPopup("config to reset");

        if (ImGui::BeginPopup("config to reset")) {
            static constexpr const char* names[]{ "Whole", "Legitbot", "Ragebot", "Triggerbot", "Backtrack", "Anti aim", "Glow", "Chams", "Esp", "Visuals", "Skin changer", "Sound", "Style", "Misc"};
            for (int i = 0; i < IM_ARRAYSIZE(names); i++) {
                if (i == 1) ImGui::Separator();

                if (ImGui::Selectable(names[i])) {
                    switch (i) {
                    case 0: config->reset(); SkinChanger::scheduleHudUpdate(); break;
                    case 1: config->legitbot = { }; break;
                    case 2: config->ragebot = { }; break;
                    case 3: config->triggerbot = { }; break;
                    case 4: config->backtrack = { }; break;
                    case 5: config->antiAim = { }; break;
                    case 6: config->glow = { }; break;
                    case 7: config->chams = { }; break;
                    case 8: config->esp = { }; break;
                    case 9: config->visuals = { }; break;
                    case 10:config->skinChanger = { }; SkinChanger::scheduleHudUpdate(); break;
                    case 11: config->sound = { }; break;
                    case 12: config->misc = { }; break;
                    }
                }
            }
            ImGui::EndPopup();
        }
        if (currentConfig != -1) {
            if (ImGui::Button("load selected", { 100.0f, 25.0f })) {
                config->load(currentConfig);
                SkinChanger::scheduleHudUpdate();
            }
            if (ImGui::Button("save selected", { 100.0f, 25.0f }))
                config->save(currentConfig);
            if (ImGui::Button("delete selected", { 100.0f, 25.0f })) {
                config->remove(currentConfig);
                currentConfig = -1;
                buffer.clear();
            }
        }
        ImGui::Columns(1);
}

void GUI::renderGui() noexcept
{
    ImGuiStyle* style = &ImGui::GetStyle();
    style->ItemSpacing = ImVec2(5.f, 2.5f);
    style->FrameBorderSize = 0.f;
    style->Colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);

    
    auto windowFlags = ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_HorizontalScrollbar | ImGuiWindowFlags_NoTitleBar;
    ImGui::SetNextWindowSize({ 770.f, 0.0f });
    ImGui::SetNextWindowSizeConstraints({ 0.f, 0.f }, { 1000.f, 10000.f });
    ImGui::Begin("dware", nullptr, windowFlags);

    if (ImGui::BeginTabBar("TabBar", ImGuiTabBarFlags_Reorderable | ImGuiTabBarFlags_FittingPolicyScroll | ImGuiTabBarFlags_NoTooltip)) {
        if (ImGui::BeginTabItem("legit")) {
            renderLegitbotWindow();
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("rage")) {
            renderRagebotWindow();
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("antiaim")) {
            renderAntiAimWindow();
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("triggerbot")) {
            renderTriggerbotWindow();
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("backtrack")) {
            renderBacktrackWindow();
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("glow")) {
            renderGlowWindow();
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("chams")) {
            renderChamsWindow();
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("esp")) {
            renderEspWindow();
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("visuals")) {
            renderVisualsWindow();
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("skin changer")) {
            renderSkinChangerWindow();
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("extra")) {
            renderSoundWindow();
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("misc")) {
            renderMiscWindow();
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("config")) {
            renderConfigWindow();
            ImGui::EndTabItem();
        }
        ImGui::EndTabBar();
    }

    ImGui::End();
}



void Active() { ImGuiStyle* Style = &ImGui::GetStyle(); Style->Colors[ImGuiCol_Button] = ImColor(25, 30, 34); Style->Colors[ImGuiCol_ButtonActive] = ImColor(25, 30, 34); Style->Colors[ImGuiCol_ButtonHovered] = ImColor(25, 30, 34); }
void Hovered() { ImGuiStyle* Style = &ImGui::GetStyle(); Style->Colors[ImGuiCol_Button] = ImColor(19, 22, 27); Style->Colors[ImGuiCol_ButtonActive] = ImColor(19, 22, 27); Style->Colors[ImGuiCol_ButtonHovered] = ImColor(19, 22, 27); }



void GUI::renderNewGui() noexcept 
{

    ImGuiStyle* Style = &ImGui::GetStyle();
    Style->WindowRounding = 0;
    Style->WindowBorderSize = 0;
    Style->ChildRounding = 0;
    Style->FrameBorderSize = 0;
    Style->Colors[ImGuiCol_WindowBg] = ImColor(0, 0, 0, 0);
    Style->Colors[ImGuiCol_ChildBg] = ImColor(19, 22, 27);
    Style->Colors[ImGuiCol_Button] = ImColor(25, 30, 34);
    Style->Colors[ImGuiCol_ButtonHovered] = ImColor(25, 30, 34);
    Style->Colors[ImGuiCol_ButtonActive] = ImColor(25, 30, 34);


    Style->Colors[ImGuiCol_ScrollbarGrab] = ImColor(255, 255, 255, 150);
    Style->Colors[ImGuiCol_ScrollbarGrabActive] = ImColor(255, 255, 255, 200);
    Style->Colors[ImGuiCol_ScrollbarGrabHovered] = ImColor(255, 255, 255, 200);

    static auto Name = "Menu";
    static auto Flags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoSavedSettings;

    static int Active_Tab = 1;
    static int Active_SubTabLegitbot = 1;
    static int Active_SubTabRagebot = 1;
    static int Active_SubTabAntiaim = 1;
    static int Active_SubTabVisuals = 1;
    static int Active_SubTabMisc = 1;
    static int Active_SubTabSkins = 1;
    static int Active_SubTabConfigs = 1;




    if (ImGui::Begin(Name, NULL, Flags))
    {

        Style->Colors[ImGuiCol_ChildBg] = ImColor(255, 255, 255, 255);

        ImGui::BeginChild("##Back", ImVec2{ 704, 434 }, false);
        {

            ImGui::SetCursorPos(ImVec2{ 2, 2 });

            Style->Colors[ImGuiCol_ChildBg] = ImColor(19, 22, 27);

            ImGui::BeginChild("##Main", ImVec2{ 700, 430 }, false);
            {
                ImGui::BeginChild("##UP", ImVec2{ 700, 45 }, false);
                {
                    ImGui::SetCursorPos(ImVec2{ 10, 6 });
                    ImGui::PushFont(fonts.tahoma34); ImGui::Text("dware"); ImGui::PopFont();

                    ImGui::SetCursorPos(ImVec2{ 145, 0 });
                    if (Active_Tab == 1) Active(); else Hovered();
                    if (ImGui::Button("legitbot", ImVec2{ 75, 45 }))
                        Active_Tab = 1;

                    ImGui::SetCursorPos(ImVec2{ 225, 0 });
                    if (Active_Tab == 2) Active(); else Hovered();
                    if (ImGui::Button("ragebot", ImVec2{ 75, 45 }))
                        Active_Tab = 2;

                    ImGui::SetCursorPos(ImVec2{ 305, 0 });
                    if (Active_Tab == 3) Active(); else Hovered();
                    if (ImGui::Button("anti-aim", ImVec2{ 75, 45 }))
                        Active_Tab = 3;

                    ImGui::SetCursorPos(ImVec2{ 385, 0 });
                    if (Active_Tab == 4) Active(); else Hovered();
                    if (ImGui::Button("visuals", ImVec2{ 75, 45 }))
                        Active_Tab = 4;

                    ImGui::SetCursorPos(ImVec2{ 465, 0 });
                    if (Active_Tab == 5) Active(); else Hovered();
                    if (ImGui::Button("misc", ImVec2{ 75, 45 }))
                        Active_Tab = 5;

                    ImGui::SetCursorPos(ImVec2{ 545, 0 });
                    if (Active_Tab == 6) Active(); else Hovered();
                    if (ImGui::Button("skins", ImVec2{ 75, 45 }))
                        Active_Tab = 6;

                    ImGui::SetCursorPos(ImVec2{ 625, 0 });
                    if (Active_Tab == 7) Active(); else Hovered();
                    if (ImGui::Button("configs", ImVec2{ 75, 45 }))
                        Active_Tab = 7;
                }
                ImGui::EndChild();

                ImGui::SetCursorPos(ImVec2{ 0, 45 });
                Style->Colors[ImGuiCol_ChildBg] = ImColor(25, 30, 34);
                Style->Colors[ImGuiCol_Button] = ImColor(25, 30, 34);
                Style->Colors[ImGuiCol_ButtonHovered] = ImColor(25, 30, 34);
                Style->Colors[ImGuiCol_ButtonActive] = ImColor(25, 30, 34);
                ImGui::BeginChild("##Childs", ImVec2{ 700, 365 }, false);
                {
                    ImGui::SetCursorPos(ImVec2{ 15, 5 });
                    Style->ChildRounding = 0;
                    ImGui::BeginChild("##Left", ImVec2{ 155, 320 }, false);
                    {
                        if (Active_Tab == 1)
                        {
                            ImGui::SetCursorPosY(10);
                            if (ImGui::Button("main                    ", ImVec2{ 80, 20 })) Active_SubTabLegitbot = 1;

                            if (ImGui::Button("backtrack               ", ImVec2{ 80, 20 })) Active_SubTabLegitbot = 2;

                            if (ImGui::Button("triggerbot              ", ImVec2{ 80, 20 })) Active_SubTabLegitbot = 3;
                        }
                        if (Active_Tab == 2)
                        {
                            ImGui::SetCursorPosY(10);
                            if (ImGui::Button("main                    ", ImVec2{ 80, 20 })) Active_SubTabRagebot = 1;

                            if (ImGui::Button("backtrack               ", ImVec2{ 80, 20 })) Active_SubTabRagebot = 2;
                        }
                        if (Active_Tab == 3)
                        {
                            ImGui::SetCursorPosY(10);
                            if (ImGui::Button("main                    ", ImVec2{ 80, 20 })) Active_SubTabAntiaim = 1;
                        }
                        else if (Active_Tab == 4)
                        {
                            ImGui::SetCursorPosY(10);
                            if (ImGui::Button("main                    ", ImVec2{ 80, 20 })) Active_SubTabVisuals = 1;

                            if (ImGui::Button("esp                     ", ImVec2{ 80, 20 })) Active_SubTabVisuals = 2;

                            if (ImGui::Button("chams                   ", ImVec2{ 80, 20 })) Active_SubTabVisuals = 3;

                            if (ImGui::Button("glow                    ", ImVec2{ 80, 20 })) Active_SubTabVisuals = 4;

                            if (ImGui::Button("removals                ", ImVec2{ 80, 20 })) Active_SubTabVisuals = 5;
                        }
                        else if (Active_Tab == 5)
                        {
                            ImGui::SetCursorPosY(10);
                            if (ImGui::Button("main                    ", ImVec2{ 80, 20 })) Active_SubTabMisc = 1;

                            if (ImGui::Button("movement                ", ImVec2{ 80, 20 })) Active_SubTabMisc = 2;

                            if (ImGui::Button("sound                   ", ImVec2{ 80, 20 })) Active_SubTabMisc = 3;

                            if (ImGui::Button("hvh misc                   ", ImVec2{ 80, 20 })) Active_SubTabMisc = 4;
                        }
                        else if (Active_Tab == 6)
                        {
                            ImGui::SetCursorPosY(10);
                            if (ImGui::Button("skins                   ", ImVec2{ 80, 20 })) Active_SubTabSkins = 1;

                            if (ImGui::Button("stickers                ", ImVec2{ 80, 20 })) Active_SubTabSkins = 2;

                            if (ImGui::Button("profile                 ", ImVec2{ 80, 20 })) Active_SubTabSkins = 3;

                            if (ImGui::Button("other                   ", ImVec2{ 80, 20 })) Active_SubTabSkins = 4;
                        }
                        else if (Active_Tab == 7)
                        {
                            ImGui::SetCursorPosY(10);
                            if (ImGui::Button("configs                 ", ImVec2{ 80, 20 })) Active_SubTabConfigs = 1;

                            if (ImGui::Button("lua                     ", ImVec2{ 80, 20 })) Active_SubTabConfigs = 2;

                        }
                        ImGui::EndChild();

                        ImGui::SetCursorPos(ImVec2{ 100, 5 });
                        Style->Colors[ImGuiCol_ChildBg] = ImColor(29, 34, 38);
                        Style->ChildRounding = 5;
                        ImGui::BeginChild("##SubMain", ImVec2{ 590, 350 }, false);
                        {

                            // ------------- Legitbot -------------

                            ImGui::SetCursorPos(ImVec2{ 10, 10 });
                            if (Active_Tab == 1 && Active_SubTabLegitbot == 1)
                            {
                                //Main
                                renderLegitbotWindow();

                            }
                            if (Active_Tab == 1 && Active_SubTabLegitbot == 2)
                            {
                                //Backtrack
                                renderBacktrackWindow();

                            }
                            if (Active_Tab == 1 && Active_SubTabLegitbot == 3)
                            {
                                //Triggerbot
                                renderTriggerbotWindow();

                            }

                            // ------------- Ragebot -------------

                            if (Active_Tab == 2 && Active_SubTabRagebot == 1)
                            {
                                //Main
                                renderRagebotWindow();

                            }
                            if (Active_Tab == 2 && Active_SubTabRagebot == 2)
                            {
                                //Backtrack
                                renderBacktrackWindow();

                            }

                            // ------------- Anti-Aim -------------

                            if (Active_Tab == 3 && Active_SubTabAntiaim == 1)
                            {
                                //Main
                                renderAntiAimWindow();

                            }

                            // ------------- VISUALS -------------

                            else if (Active_Tab == 4 && Active_SubTabVisuals == 1)
                            {
                                //Main
                                renderVisualsWindow();

                            }
                            else if (Active_Tab == 4 && Active_SubTabVisuals == 2)
                            {
                                //Esp
                                renderEspWindow();

                            }
                            else if (Active_Tab == 4 && Active_SubTabVisuals == 3)
                            {
                                //Chams
                                renderChamsWindow();

                            }
                            else if (Active_Tab == 4 && Active_SubTabVisuals == 4)
                            {
                                //Glow
                                renderGlowWindow();

                            }
                            else if (Active_Tab == 4 && Active_SubTabVisuals == 5)
                            {
                                //Removals
                                ImGui::Checkbox("remove fog", &config->visuals.noFog);
                                ImGui::Checkbox("remove hands", &config->visuals.noHands);
                                ImGui::Checkbox("remove sleeves", &config->visuals.noSleeves);
                                ImGui::Checkbox("remove weapons", &config->visuals.noWeapons);
                                ImGui::Checkbox("remove smoke", &config->visuals.noSmoke);
                                ImGui::Checkbox("remove blur", &config->visuals.noBlur);
                                ImGui::Checkbox("remove scope overlay", &config->visuals.noScopeOverlay);
                                ImGui::Checkbox("remove grass", &config->visuals.noGrass);
                                ImGui::Checkbox("remove shadows", &config->visuals.noShadows);

                            }

                            // ------------- MISC -------------

                            else if (Active_Tab == 5 && Active_SubTabMisc == 1)
                            {
                                //Main
                                renderMiscWindow();

                            }
                            else if (Active_Tab == 5 && Active_SubTabMisc == 2)
                            {
                                //Movement
                                ImGui::Checkbox("bunnyhop", &config->misc.bunnyHop);
                                ImGui::Checkbox("infinite stamina", &config->misc.fastDuck);
                                ImGui::Checkbox("edge jump", &config->misc.edgejump);
                                ImGui::SameLine();
                                hotkey(config->misc.edgejumpkey);
                                ImGui::Checkbox("jump bug", &config->misc.jumpbug);
                                ImGui::SameLine();
                                hotkey(config->misc.jumpbugkey);

                            }
                            else if (Active_Tab == 5 && Active_SubTabMisc == 3)
                            {
                                //Sound
                                renderSoundWindow();

                            }
                            else if (Active_Tab == 5 && Active_SubTabMisc == 4)
                            {
                                //HVH

                                ImGui::Columns(2, nullptr, false);
                                ImGui::SetColumnOffset(1, 450.0f);
                                ImGui::PushItemWidth(150.0f);

                                //   ---- end result ----
                                ImGui::Checkbox("fake lag", &config->antiAim.fakeLag);
                                ImGui::Combo("fake lag mode", &config->antiAim.fakeLagMode, "Maximum\0Adaptive\0Random\0");
                                ImGui::SliderInt("fake lag amount", &config->antiAim.fakeLagAmount, 1, 16, "%d ticks");

                                ImGui::Separator();
                                ImGui::Checkbox("rage auto-strafer", &config->misc.autoStrafe);
                                ImGui::Text("fake duck key");
                                ImGui::SameLine();
                                hotkey(config->antiAim.fakeDuckKey);
                                ImGui::Checkbox("slowwalk", &config->misc.slowwalk);
                                ImGui::SameLine();
                                hotkey(config->misc.slowwalkKey);
                                ImGui::Checkbox("quick peek", &config->misc.quickpeek);
                                ImGui::SameLine();
                                hotkey(config->misc.quickpeekkey);
                                ImGui::Checkbox("aa lines", &config->visuals.aaLines);
                            }

                            // ------------- SKINS -------------

                            else if (Active_Tab == 6 && Active_SubTabSkins == 1)
                            {
                                //Skins
                                renderSkinChangerWindow();

                            }
                            else if (Active_Tab == 6 && Active_SubTabSkins == 2)
                            {
                                //Stickers

                            }
                            else if (Active_Tab == 6 && Active_SubTabSkins == 3)
                            {
                                //Profile

                            }
                            else if (Active_Tab == 6 && Active_SubTabSkins == 4)
                            {
                                //Others
                            }

                            // ------------- CONFIG & LUA -------------

                            else if (Active_Tab == 7 && Active_SubTabConfigs == 1)
                            {
                                //Configs
                                renderConfigWindow();

                            }
                            else if (Active_Tab == 7 && Active_SubTabConfigs == 2)
                            {
                                //Lua's

                            }
                        }
                        ImGui::EndChild();
                    }
                    ImGui::EndChild();

                    ImGui::SetCursorPos(ImVec2{ 0, 410 });
                    Style->Colors[ImGuiCol_ChildBg] = ImColor(45, 50, 54);
                    Style->ChildRounding = 0;
                    ImGui::BeginChild("##Text", ImVec2{ 700, 20 }, false);
                    {
                        ImGui::SetCursorPos(ImVec2{ 580, 2 });
                        ImGui::Text("diamondware.xyz");
                    }
                    ImGui::EndChild();
                }
                ImGui::EndChild();
            }
            ImGui::EndChild();
        }
        ImGui::End();
    }
}



