#pragma once

enum class FrameStage;
class GameEvent;

namespace Visuals
{
    void nightMode() noexcept;
    void modifySmoke(FrameStage stage) noexcept;
    void thirdperson() noexcept;
    void updateBrightness() noexcept;
    void removeShadows() noexcept;
    void applyScreenEffects() noexcept;
    void hitEffect(GameEvent* event = nullptr) noexcept;
    void hitMarker(GameEvent* event = nullptr) noexcept;
    void disablePostProcessing(FrameStage stage) noexcept;
    void reduceFlashEffect() noexcept;
    bool removeHands(const char* modelName) noexcept;
    bool removeSleeves(const char* modelName) noexcept;
    bool removeWeapons(const char* modelName) noexcept;
    void skybox(FrameStage stage) noexcept;
    void bulletBeams(GameEvent* event) noexcept;
    void aaLines() noexcept;
    void PenetrationCrosshair() noexcept;
}
