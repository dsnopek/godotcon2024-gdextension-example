
#pragma once

#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/classes/texture_rect.hpp>
#include <godot_cpp/core/gdvirtual.gen.inc>

using namespace godot;

enum TrafficLightType {
    TRAFFIC_LIGHT_GO,
    TRAFFIC_LIGHT_STOP,
    TRAFFIC_LIGHT_CAUTION,
};

VARIANT_ENUM_CAST(TrafficLightType);

class TrafficLight : public Control {
	GDCLASS(TrafficLight, Control);

public:
private:
	TextureRect *texture_rect = nullptr;

	Ref<Texture2D> stop_texture;
	Ref<Texture2D> go_texture;
	Ref<Texture2D> caution_texture;

	TrafficLightType light = TRAFFIC_LIGHT_CAUTION;

protected:
	static void _bind_methods();

	void _notification(int p_what);

public:
	void set_stop_texture(const Ref<Texture2D> &p_texture);
	Ref<Texture2D> get_stop_texture() const;

	void set_go_texture(const Ref<Texture2D> &p_texture);
	Ref<Texture2D> get_go_texture() const;

	void set_caution_texture(const Ref<Texture2D> &p_texture);
	Ref<Texture2D> get_caution_texture() const;

	void set_light(TrafficLightType p_light);
	TrafficLightType get_light() const;

	void show_next_light();

	GDVIRTUAL1RC(TrafficLightType, _get_next_light, TrafficLightType);

	TrafficLight();
};
