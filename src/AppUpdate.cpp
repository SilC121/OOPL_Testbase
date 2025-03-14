#include "App.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"

void App::Update() {
    // TODO: Add your own logics to finish the tasks in README.md || Util::Input::IfExit()
    if (Util::Input::IsKeyPressed(Util::Keycode::W)){
        m_people->SetPivot({m_people->GetPivot().x,m_people->GetPivot().y-5});
        //m_character->SetPosition({m_character->GetPosition().x,m_character->GetPosition().y+5});
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::A) ) {
        m_people->SetPivot({m_people->GetPivot().x+5,m_people->GetPivot().y});
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::S) ) {
        m_people->SetPivot({m_people->GetPivot().x,m_people->GetPivot().y+5});
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::D) ) {
        m_people->SetPivot({m_people->GetPivot().x-5,m_people->GetPivot().y});
    }

    /*
     *  Do not touch the code below as they serve the purpose for validating the tasks,
     *  rendering the frame, and exiting the game.
    */

    if (Util::Input::IsKeyPressed(Util::Keycode::ESCAPE) || Util::Input::IfExit()) {
        m_CurrentState = State::END;
    }

    if (m_EnterDown) {
        if (!Util::Input::IsKeyPressed(Util::Keycode::RETURN)) {
            ValidTask();
        }
    }
    m_EnterDown = Util::Input::IsKeyPressed(Util::Keycode::RETURN);

    m_Root.Update();
}
