#include <SFML/Graphics.hpp>
#include "core/PhysicsEngine.h"
#include "core/RigidBody.h"
#include "core/Vector3D.h"

int main() {
    constexpr unsigned int W = 800;
    constexpr unsigned int H = 600;
    constexpr float RADIUS    = 20.f;
    constexpr float RESTITUTION = 0.80f; // energy kept on each bounce

    sf::RenderWindow window(sf::VideoMode({W, H}), "Physics Engine Demo");
    window.setFramerateLimit(60);

    // Ball starting near top-center with a rightward nudge
    RigidBody ball(Vector3D(W / 2.f, RADIUS * 2.f, 0.f), 1.f);
    ball.setVelocity(Vector3D(220.f, 0.f, 0.f));

    // Gravity in screen-space (y increases downward, pixels/s^2)
    const Vector3D gravity(0.f, 900.f, 0.f);

    sf::CircleShape shape(RADIUS);
    shape.setFillColor(sf::Color::Cyan);
    shape.setOutlineThickness(2.f);
    shape.setOutlineColor(sf::Color::White);
    shape.setOrigin({RADIUS, RADIUS});

    sf::Clock clock;

    while (window.isOpen()) {
        // --- Events ---
        while (const std::optional<sf::Event> event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
            if (const auto* key = event->getIf<sf::Event::KeyPressed>())
                if (key->scancode == sf::Keyboard::Scan::Escape)
                    window.close();
        }

        // --- Physics step ---
        float dt = clock.restart().asSeconds();
        if (dt > 0.033f) dt = 0.033f; // cap to avoid giant jumps after pauses

        PhysicsEngine::applyForce(ball, gravity, dt);
        PhysicsEngine::update(ball, dt);

        // --- Boundary collisions ---
        Vector3D pos = ball.getPosition();
        Vector3D vel = ball.getVelocity();

        if (pos.y + RADIUS >= static_cast<float>(H)) {
            pos.y = H - RADIUS;
            vel.y = -vel.y * RESTITUTION;
        }
        if (pos.y - RADIUS <= 0.f) {
            pos.y = RADIUS;
            vel.y = -vel.y * RESTITUTION;
        }
        if (pos.x - RADIUS <= 0.f) {
            pos.x = RADIUS;
            vel.x = -vel.x * RESTITUTION;
        }
        if (pos.x + RADIUS >= static_cast<float>(W)) {
            pos.x = W - RADIUS;
            vel.x = -vel.x * RESTITUTION;
        }

        ball.setPosition(pos);
        ball.setVelocity(vel);

        // --- Render ---
        window.clear(sf::Color(20, 20, 30));
        shape.setPosition({pos.x, pos.y});
        window.draw(shape);
        window.display();
    }

    return 0;
}
