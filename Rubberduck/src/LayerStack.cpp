/* *************************************************************************** */
/*                 *#########                                                  */
/*                ##........../##           KWAK!                              */
/*              *#,.......,##....#######  /                                    */
/*              ##........./....##////##                                       */
/*    ##          ##...........,##((##                                         */
/*   #.###/        ##,..........*                                              */
/*  #(.....(######(###*........,##                                             */
/* ##.............................##      File    : LayerStack.cpp             */
/* ##.    __       __  o       __  ##                                          */
/* ##.   |_  |\ | | __ | |\ | |_    *#.   Created : Gabcollet                  */
/*  ##   |__ | \| |__| | | \| |__   ,#,             2022/06/23 15:37:44        */
/*   ##.............................##                                         */
/*    /##........................*##      Updated : Gabcollet                  */
/*       ###/................*###.                  2022/06/23 15:37:44        */
/*            ##############.                                                  */
/* *************************************************************************** */

#include "LayerStack.hpp"

namespace Rubberduck
{

    LayerStack::LayerStack()
    {
        _layerinsert = _layers.begin();
    }

    LayerStack::~LayerStack()
    {
        for (Layer* layer : _layers)
            delete layer;
    }
    
    void LayerStack::PushLayer(Layer* layer) 
    {
        _layerinsert = _layers.emplace(_layerinsert, layer);
    }
    
    void LayerStack::PushOverlay(Layer* overlay) 
    {
        _layers.emplace_back(overlay);
    }
    
    void LayerStack::PopLayer(Layer* layer) 
    {
        auto it = std::find(_layers.begin(), _layers.end(), layer);
        if (it != _layers.end())
        {
            _layers.erase(it);
            _layerinsert--;
        }
    }
    
    void LayerStack::PopOverlay(Layer* overlay) 
    {
        auto it = std::find(_layers.begin(), _layers.end(), overlay);
        if (it != _layers.end())
            _layers.erase(it);
    }
}