#pragma once

#include <unordered_map>
#include <memory>
#include <optional>

namespace pengine {
    template <class Resource, class Identifier>
    class ResourceManager {
        private:
            std::unordered_map<Identifier, std::shared_ptr<Resource>> _resources;
        public:
            void insert(Identifier& id, Resource resouce) {
                _resources.emplace(std::pair(id, std::make_shared(resouce)));
            }

            std::optional<std::shared_ptr<Identifier>> get(Identifier& id){
                auto q = _resources.find(id);
                if(q == _resources.end()){
                    return std::nullopt;
                }
                return _resources[id];
            }

            void remove(Identifier& id) {
                auto q = _resources.find(id);
                if(q == _resources.end()){
                    return;
                }
                _resources.erase(id);
            }
    };
}