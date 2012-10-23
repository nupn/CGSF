// This file has been generated by Py++.

#include "boost/python.hpp"
#include "python_CEGUI.h"
#include "DefaultResourceProvider.pypp.hpp"

namespace bp = boost::python;

struct DefaultResourceProvider_wrapper : CEGUI::DefaultResourceProvider, bp::wrapper< CEGUI::DefaultResourceProvider > {

    DefaultResourceProvider_wrapper(CEGUI::DefaultResourceProvider const & arg )
    : CEGUI::DefaultResourceProvider( arg )
      , bp::wrapper< CEGUI::DefaultResourceProvider >(){
        // copy constructor
        
    }

    DefaultResourceProvider_wrapper( )
    : CEGUI::DefaultResourceProvider( )
      , bp::wrapper< CEGUI::DefaultResourceProvider >(){
        // null constructor
    
    }

    virtual ::size_t getResourceGroupFileNames( ::std::vector< CEGUI::String > & out_vec, ::CEGUI::String const & file_pattern, ::CEGUI::String const & resource_group ) {
        if( bp::override func_getResourceGroupFileNames = this->get_override( "getResourceGroupFileNames" ) )
            return func_getResourceGroupFileNames( boost::ref(out_vec), boost::ref(file_pattern), boost::ref(resource_group) );
        else{
            return this->CEGUI::DefaultResourceProvider::getResourceGroupFileNames( boost::ref(out_vec), boost::ref(file_pattern), boost::ref(resource_group) );
        }
    }
    
    ::size_t default_getResourceGroupFileNames( ::std::vector< CEGUI::String > & out_vec, ::CEGUI::String const & file_pattern, ::CEGUI::String const & resource_group ) {
        return CEGUI::DefaultResourceProvider::getResourceGroupFileNames( boost::ref(out_vec), boost::ref(file_pattern), boost::ref(resource_group) );
    }

    virtual void loadRawDataContainer( ::CEGUI::String const & filename, ::CEGUI::RawDataContainer & output, ::CEGUI::String const & resourceGroup ) {
        if( bp::override func_loadRawDataContainer = this->get_override( "loadRawDataContainer" ) )
            func_loadRawDataContainer( boost::ref(filename), boost::ref(output), boost::ref(resourceGroup) );
        else{
            this->CEGUI::DefaultResourceProvider::loadRawDataContainer( boost::ref(filename), boost::ref(output), boost::ref(resourceGroup) );
        }
    }
    
    void default_loadRawDataContainer( ::CEGUI::String const & filename, ::CEGUI::RawDataContainer & output, ::CEGUI::String const & resourceGroup ) {
        CEGUI::DefaultResourceProvider::loadRawDataContainer( boost::ref(filename), boost::ref(output), boost::ref(resourceGroup) );
    }

    virtual void unloadRawDataContainer( ::CEGUI::RawDataContainer & data ) {
        if( bp::override func_unloadRawDataContainer = this->get_override( "unloadRawDataContainer" ) )
            func_unloadRawDataContainer( boost::ref(data) );
        else{
            this->CEGUI::DefaultResourceProvider::unloadRawDataContainer( boost::ref(data) );
        }
    }
    
    void default_unloadRawDataContainer( ::CEGUI::RawDataContainer & data ) {
        CEGUI::DefaultResourceProvider::unloadRawDataContainer( boost::ref(data) );
    }

};

void register_DefaultResourceProvider_class(){

    { //::CEGUI::DefaultResourceProvider
        typedef bp::class_< DefaultResourceProvider_wrapper, bp::bases< CEGUI::ResourceProvider > > DefaultResourceProvider_exposer_t;
        DefaultResourceProvider_exposer_t DefaultResourceProvider_exposer = DefaultResourceProvider_exposer_t( "DefaultResourceProvider", bp::init< >("*************************************************************************\n\
           Construction and Destruction\n\
        *************************************************************************\n") );
        bp::scope DefaultResourceProvider_scope( DefaultResourceProvider_exposer );
        { //::CEGUI::DefaultResourceProvider::clearResourceGroupDirectory
        
            typedef void ( ::CEGUI::DefaultResourceProvider::*clearResourceGroupDirectory_function_type )( ::CEGUI::String const & ) ;
            
            DefaultResourceProvider_exposer.def( 
                "clearResourceGroupDirectory"
                , clearResourceGroupDirectory_function_type( &::CEGUI::DefaultResourceProvider::clearResourceGroupDirectory )
                , ( bp::arg("resourceGroup") )
                , "*!\n\
                \n\
                    clears any currently set directory for the specified resource group\n\
                    identifier.\n\
            \n\
                @param resourceGroup\n\
                    The resource group identifier for which the associated directory is to\n\
                    be cleared.\n\
                *\n" );
        
        }
        { //::CEGUI::DefaultResourceProvider::getResourceGroupDirectory
        
            typedef ::CEGUI::String const & ( ::CEGUI::DefaultResourceProvider::*getResourceGroupDirectory_function_type )( ::CEGUI::String const & ) ;
            
            DefaultResourceProvider_exposer.def( 
                "getResourceGroupDirectory"
                , getResourceGroupDirectory_function_type( &::CEGUI::DefaultResourceProvider::getResourceGroupDirectory )
                , ( bp::arg("resourceGroup") )
                , bp::return_value_policy< bp::copy_const_reference >()
                , "*!\n\
                \n\
                    Return the directory associated with the specified resource group\n\
                    identifier.\n\
            \n\
                @param resourceGroup\n\
                    The resource group identifier for which the associated directory is to\n\
                    be returned.\n\
            \n\
                @return\n\
                    String object describing the directory currently associated with resource\n\
                    group identifier  resourceGroup.\n\
            \n\
                \note\n\
                    This member is not defined as being const because it may cause\n\
                    creation of an 'empty' directory specification for the resourceGroup\n\
                    if the resourceGroup has not previously been accessed.\n\
                *\n" );
        
        }
        { //::CEGUI::DefaultResourceProvider::getResourceGroupFileNames
        
            typedef ::size_t ( ::CEGUI::DefaultResourceProvider::*getResourceGroupFileNames_function_type )( ::std::vector< CEGUI::String > &,::CEGUI::String const &,::CEGUI::String const & ) ;
            typedef ::size_t ( DefaultResourceProvider_wrapper::*default_getResourceGroupFileNames_function_type )( ::std::vector< CEGUI::String > &,::CEGUI::String const &,::CEGUI::String const & ) ;
            
            DefaultResourceProvider_exposer.def( 
                "getResourceGroupFileNames"
                , getResourceGroupFileNames_function_type(&::CEGUI::DefaultResourceProvider::getResourceGroupFileNames)
                , default_getResourceGroupFileNames_function_type(&DefaultResourceProvider_wrapper::default_getResourceGroupFileNames)
                , ( bp::arg("out_vec"), bp::arg("file_pattern"), bp::arg("resource_group") ) );
        
        }
        { //::CEGUI::DefaultResourceProvider::loadRawDataContainer
        
            typedef void ( ::CEGUI::DefaultResourceProvider::*loadRawDataContainer_function_type )( ::CEGUI::String const &,::CEGUI::RawDataContainer &,::CEGUI::String const & ) ;
            typedef void ( DefaultResourceProvider_wrapper::*default_loadRawDataContainer_function_type )( ::CEGUI::String const &,::CEGUI::RawDataContainer &,::CEGUI::String const & ) ;
            
            DefaultResourceProvider_exposer.def( 
                "loadRawDataContainer"
                , loadRawDataContainer_function_type(&::CEGUI::DefaultResourceProvider::loadRawDataContainer)
                , default_loadRawDataContainer_function_type(&DefaultResourceProvider_wrapper::default_loadRawDataContainer)
                , ( bp::arg("filename"), bp::arg("output"), bp::arg("resourceGroup") ) );
        
        }
        { //::CEGUI::DefaultResourceProvider::setResourceGroupDirectory
        
            typedef void ( ::CEGUI::DefaultResourceProvider::*setResourceGroupDirectory_function_type )( ::CEGUI::String const &,::CEGUI::String const & ) ;
            
            DefaultResourceProvider_exposer.def( 
                "setResourceGroupDirectory"
                , setResourceGroupDirectory_function_type( &::CEGUI::DefaultResourceProvider::setResourceGroupDirectory )
                , ( bp::arg("resourceGroup"), bp::arg("directory") )
                , "*!\n\
                \n\
                    Set the directory associated with a given resource group identifier.\n\
            \n\
                @param resourceGroup\n\
                    The resource group identifier whose directory is to be set.\n\
            \n\
                @param directory\n\
                    The directory to be associated with resource group identifier\n\
                     resourceGroup\n\
            \n\
                @return\n\
                    Nothing.\n\
                *\n" );
        
        }
        { //::CEGUI::DefaultResourceProvider::unloadRawDataContainer
        
            typedef void ( ::CEGUI::DefaultResourceProvider::*unloadRawDataContainer_function_type )( ::CEGUI::RawDataContainer & ) ;
            typedef void ( DefaultResourceProvider_wrapper::*default_unloadRawDataContainer_function_type )( ::CEGUI::RawDataContainer & ) ;
            
            DefaultResourceProvider_exposer.def( 
                "unloadRawDataContainer"
                , unloadRawDataContainer_function_type(&::CEGUI::DefaultResourceProvider::unloadRawDataContainer)
                , default_unloadRawDataContainer_function_type(&DefaultResourceProvider_wrapper::default_unloadRawDataContainer)
                , ( bp::arg("data") ) );
        
        }
    }

}
