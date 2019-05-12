#include "htmlcontentgenerator.h"
#include "filesystemmodel.h"
#include <Mustache\mustache.hpp>
#include <fstream>

//Configuration hTMLGenerator;
//DataModel item1;

//static std::string mustasheTemplate{R"(<!DOCTYPE html>
//                             <html>

//                             <head>
//                             <title>FileServer</title>
//                             <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
//                             </head>

//                             <body>
//                             <p>&nbsp;</p>
//                             <h1>File Server</h1>
//                             <p>&nbsp;</p>
//                             <p>&nbsp;</p>

//                             <table style="width:100%">
//                             <tbody>
//                             <tr>
//                             {{#showIcons}}
//                             <td>&nbsp;</td>
//                             {{/showIcons}}
//                             <td><strong>Name</strong></td>
//                             {{#showSize}}
//                             <td><strong>Size</strong></td>
//                             {{/showSize}}
//                             {{#showDetails}}
//                             <td><strong>Information</strong></td>
//                             {{/showDetails}}
//                             </tr>

//                             {{#dirEntryList}}
//                             <tr>
//                             {{#showIcons}}
//                             <td>{{{fileIcon}}}</td>
//                             {{/showIcons}}
//                             <td>{{fileName}}</td>
//                             {{#showSize}}
//                             <td>{{fileSize}}</td>
//                             {{/showSize}}
//                             {{#showDetails}}
//                             <td>{{fileDetails}}</td>
//                             {{/showDetails}}
//                             </tr>
//                             {{/dirEntryList}}
//                             </tbody>
//                             </table>

//                             <p>&nbsp;</p>
//                             </body>
//                             </html>
//                             )"};

struct FileSystemItems
{
    std::string name;
    bool isFolder;
};

std::vector<FileSystemItems> fsItemsList = {{"..", false},
                                            {"Test Folder", true},
                                            {"Test Folder", true},
                                            {"Test Folder", true},
                                            {"Test Folder", true},
                                            {"Test Folder", true},
                                            {"Test Folder", true},
                                            {"Test Folder", true},
                                            {"file.txt", false},
                                            {"file.txt", false},
                                            {"file.txt", false},
                                            {"file.txt", false},
                                            {"file.txt", false},
                                            {"file.txt", false},
                                            {"file.txt", false},
                                            {"file.txt", false},
                                            {"file.txt", false},
                                            {"file.txt", false},
                                            {"file.txt", false}
                                           };

HTMLContentGenerator::~HTMLContentGenerator()
{

}

std::string HTMLContentGenerator::generate(const std::string &path)
{
    //return mustasheTemplate;

    std::string mustasheTemplate{""};
    std::ifstream templateFile;

    templateFile.open("./template.html");
    if(!templateFile.is_open())
    {
        std::cout<<"file \"template.html\" not found"<<std::endl;
    }
    else
    {
        std::string fileLine;
        while (!templateFile.eof())
         {
             std::getline(templateFile, fileLine);
             mustasheTemplate+=fileLine;
         }
    }

    const bool showIconsColumn = true, showSizeColumn = true, showDetailsConst = true;
    kainjow::mustache::mustache tmpl{mustasheTemplate};

    kainjow::mustache::data mustashe{};
    mustashe.set("showIcons", showIconsColumn ? kainjow::mustache::data::type::bool_true
                                              : kainjow::mustache::data::type::bool_false);
    mustashe.set("showSize", showSizeColumn ? kainjow::mustache::data::type::bool_true
                                            : kainjow::mustache::data::type::bool_false);
    mustashe.set("showDetails", showDetailsConst ? kainjow::mustache::data::type::bool_true
                                                 : kainjow::mustache::data::type::bool_false);


    kainjow::mustache::data iconsListMustashe{kainjow::mustache::data::type::list};
    kainjow::mustache::data fileNamesListMustashe{kainjow::mustache::data::type::list};
    kainjow::mustache::data sizesListMustashe{kainjow::mustache::data::type::list};
    kainjow::mustache::data detailsListMustashe{kainjow::mustache::data::type::list};

    kainjow::mustache::data dirEntryListMustashe{kainjow::mustache::data::type::list};
    for (int fileIndex = 0; fileIndex < model()->count();  fileIndex++)
    {
        kainjow::mustache::data dirEntryMustashe;

        dirEntryMustashe.set("showIcons", showIconsColumn ? kainjow::mustache::data::type::bool_true
                                                          : kainjow::mustache::data::type::bool_false);

        // File Icon
        if (showIconsColumn)
        {
            dirEntryMustashe.set("showIcons", kainjow::mustache::data::type::bool_true);

            if (!model()->isDir(fileIndex))
            {
                if (model()->name(fileIndex) != "..")
                {
                    dirEntryMustashe.set("fileIcon", R"(<i class="fa fa-sticky-note"></i>)");
                }
                else
                {
                    dirEntryMustashe.set("fileIcon", R"(<i class="fa fa-level-up"></i>)");
                }
            }
            else
            {
                dirEntryMustashe.set("fileIcon", R"(<i class="fa fa-folder"></i>)");
            }
        }
        else
        {
            dirEntryMustashe.set("showIcons", kainjow::mustache::data::type::bool_false);
        }

        // File Name
        dirEntryMustashe.set("fileName", model()->name(fileIndex));

        // File Size
        if (showSizeColumn)
        {
            dirEntryMustashe.set("showSize", kainjow::mustache::data::type::bool_true);

            if (!model()->isDir(fileIndex) && model()->name(fileIndex) != "..")
            {
                dirEntryMustashe.set("fileSize", "1 K");
            }
            else
            {
                dirEntryMustashe.set("fileSize", "-");
            }
        }
        else
        {
            dirEntryMustashe.set("showSize", kainjow::mustache::data::type::bool_false);
        }

        // File details
        if (showDetailsConst)
        {
            dirEntryMustashe.set("showDetails", kainjow::mustache::data::type::bool_true);

            if (!model()->isDir(fileIndex) && model()->name(fileIndex) != "..")
            {
                dirEntryMustashe.set("fileDetails", "details");
            }
            else
            {
                dirEntryMustashe.set("fileDetails", "-");
            }
        }
        else
        {
            dirEntryMustashe.set("showDetails", kainjow::mustache::data::type::bool_false);
        }

        dirEntryListMustashe << dirEntryMustashe;
    }

    mustashe.set("dirEntryList", dirEntryListMustashe);

    return tmpl.render(mustashe);

}

void HTMLContentGenerator::setConfiguration(Configuration configuration)
{

}
