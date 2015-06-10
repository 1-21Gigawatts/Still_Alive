#ifndef TEXTURE_MANAGER_HPP_INCLUDED
#define TEXTURE_MANAGER_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <string>
#include <map> // Creates a map of strings to textures

class TextureManager
{
    private:

    /* Array of textures used */
    std::map<std::string, sf::Texture> textures;

    public:

    /* Add a texture from a file */
    void loadTexture(const std::string& name, const std::string &filename);

    /* Translate an id into a reference */
    sf::Texture& getRef(const std::string& texture);

    /* Constructor */
    TextureManager()
    {
    }
};

#endif // TEXTURE_MANAGER_HPP_INCLUDED
