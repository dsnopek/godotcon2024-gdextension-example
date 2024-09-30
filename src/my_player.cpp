
#include "my_player.h"

#include <godot_cpp/classes/input.hpp>

void MyPlayer::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_speed", "speed"), &MyPlayer::set_speed);
	ClassDB::bind_method(D_METHOD("get_speed"), &MyPlayer::get_speed);

	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "speed"), "set_speed", "get_speed");
}

void MyPlayer::_physics_process(double p_delta) {
	Input *input = Input::get_singleton();

	Vector2 velocity;
    if (input->is_action_pressed("ui_up")) {
		velocity.y -= 1.0;
    } else if (input->is_action_pressed("ui_down")) {
		velocity.y += 1.0;
	} else if (input->is_action_pressed("ui_left")) {
		velocity.x -= 1.0;
	} else if (input->is_action_pressed("ui_right")) {
		velocity.x += 1.0;
	}
	set_velocity(velocity.normalized() * speed);

	move_and_slide();
}

void MyPlayer::set_speed(float p_speed) {
	speed = p_speed;
}

float MyPlayer::get_speed() const {
	return speed;
}

MyPlayer::MyPlayer() {
}
