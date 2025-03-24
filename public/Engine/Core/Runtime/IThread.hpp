#pragma once

#include <functional>
#include <string>
#include <string_view>

namespace engine::core::runtime {
    struct IThread {
        virtual ~IThread() = default;

        virtual void Start() = 0;
        virtual void Stop() = 0;
        virtual void Join() = 0;

        virtual bool IsRunning() const = 0;

        virtual void SetName(std::string_view name) = 0;
        virtual std::string GetName() const = 0;

        template <typename Function, typename... Args>
        void SetTaskFunc(Function&& func, Args&&... args) {
            SetTaskFuncInternal(std::bind(std::forward<Function>(func), std::forward<Args>(args)...));
        }
    protected:
        virtual void SetTaskFuncInternal(std::function<void()> task) = 0;
    };
}
