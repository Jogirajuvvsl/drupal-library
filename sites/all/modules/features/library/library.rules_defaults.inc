<?php
/**
 * @file
 * library.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function library_default_rules_configuration() {
  $items = array();
  $items['rules_add_stock'] = entity_import('rules_config', '{ "rules_add_stock" : {
      "LABEL" : "Add Stock",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ACCESS_EXPOSED" : "1",
      "USES VARIABLES" : {
        "book" : { "label" : "Book", "type" : "node" },
        "cop" : { "label" : "No. of Copies", "type" : "integer" }
      },
      "ACTION SET" : [
        { "entity_create" : {
            "USING" : {
              "type" : "node",
              "param_type" : "transaction",
              "param_title" : "Transaction",
              "param_author" : [ "site:current-user" ]
            },
            "PROVIDE" : { "entity_created" : { "entity_created" : "Created entity" } }
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-user" ],
            "value" : [ "site:current-user" ]
          }
        },
        { "data_set" : { "data" : [ "entity-created:field-book" ], "value" : [ "book" ] } },
        { "data_set" : {
            "data" : [ "entity-created:field-transaction-date" ],
            "value" : [ "site:current-date" ]
          }
        },
        { "data_set" : { "data" : [ "entity-created:field-no-of-copies" ], "value" : [ "cop" ] } },
        { "data_set" : { "data" : [ "entity-created:field-transaction-type" ], "value" : "24" } },
        { "entity_save" : { "data" : [ "entity-created" ], "immediate" : "1" } }
      ]
    }
  }');
  $items['rules_delete_stock'] = entity_import('rules_config', '{ "rules_delete_stock" : {
      "LABEL" : "Delete Stock",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ACCESS_EXPOSED" : "1",
      "USES VARIABLES" : {
        "book" : { "label" : "Book", "type" : "node" },
        "cop" : { "label" : "No. of Copies", "type" : "integer" }
      },
      "ACTION SET" : [
        { "entity_create" : {
            "USING" : {
              "type" : "node",
              "param_type" : "transaction",
              "param_title" : "Transaction",
              "param_author" : [ "site:current-user" ]
            },
            "PROVIDE" : { "entity_created" : { "entity_created" : "Created entity" } }
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-user" ],
            "value" : [ "site:current-user" ]
          }
        },
        { "data_set" : { "data" : [ "entity-created:field-book" ], "value" : [ "book" ] } },
        { "data_set" : {
            "data" : [ "entity-created:field-transaction-date" ],
            "value" : [ "site:current-date" ]
          }
        },
        { "data_set" : { "data" : [ "entity-created:field-no-of-copies" ], "value" : [ "cop" ] } },
        { "data_set" : { "data" : [ "entity-created:field-transaction-type" ], "value" : "25" } },
        { "entity_save" : { "data" : [ "entity-created" ], "immediate" : "1" } }
      ]
    }
  }');
  $items['rules_issue'] = entity_import('rules_config', '{ "rules_issue" : {
      "LABEL" : "Issue",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "REQUIRES" : [ "custom_library", "rules_conditional", "rules" ],
      "ACCESS_EXPOSED" : "1",
      "USES VARIABLES" : { "book" : { "label" : "Book", "type" : "node" } },
      "ACTION SET" : [
        { "custom_library_issue_check" : {
            "USING" : { "book" : [ "book" ] },
            "PROVIDE" : { "check" : { "check" : "The Status of the action" } }
          }
        },
        { "CONDITIONAL" : [
            {
              "IF" : { "text_matches" : { "text" : [ "check" ], "match" : "1" } },
              "DO" : [
                { "entity_create" : {
                    "USING" : {
                      "type" : "node",
                      "param_type" : "transaction",
                      "param_title" : "Transaction",
                      "param_author" : [ "site:current-user" ]
                    },
                    "PROVIDE" : { "entity_created" : { "entity_created" : "Created entity" } }
                  }
                },
                { "data_set" : {
                    "data" : [ "entity-created:field-user" ],
                    "value" : [ "site:current-user" ]
                  }
                },
                { "data_set" : { "data" : [ "entity-created:field-book" ], "value" : [ "book" ] } },
                { "data_set" : {
                    "data" : [ "entity-created:field-transaction-date" ],
                    "value" : [ "site:current-date" ]
                  }
                },
                { "data_set" : { "data" : [ "entity-created:field-transaction-type" ], "value" : "21" } },
                { "data_set" : { "data" : [ "entity-created:field-no-of-copies" ], "value" : "-1" } },
                { "entity_save" : { "data" : [ "entity-created" ], "immediate" : "1" } },
                { "entity_create" : {
                    "USING" : {
                      "type" : "node",
                      "param_type" : "issue",
                      "param_title" : "Issue",
                      "param_author" : [ "site:current-user" ]
                    },
                    "PROVIDE" : { "entity_created" : { "entity_created1" : "Created entity" } }
                  }
                },
                { "data_set" : {
                    "data" : [ "entity-created1:field-user" ],
                    "value" : [ "site:current-user" ]
                  }
                },
                { "data_set" : { "data" : [ "entity-created1:field-book" ], "value" : [ "book" ] } },
                { "data_set" : {
                    "data" : [ "entity-created1:field-issue-date" ],
                    "value" : [ "site:current-date" ]
                  }
                },
                { "custom_library_return_date" : { "PROVIDE" : { "date" : { "date" : "The return date of the borrowed book" } } } },
                { "data_set" : { "data" : [ "entity-created1:field-return-date" ], "value" : [ "date" ] } },
                { "data_set" : { "data" : [ "entity-created1:field-fine" ], "value" : "0" } },
                { "data_set" : { "data" : [ "entity-created1:field-status" ], "value" : "Issued" } },
                { "entity_save" : { "data" : [ "entity-created1" ], "immediate" : "1" } }
              ]
            },
            {
              "ELSE IF" : { "text_matches" : { "text" : [ "check" ], "match" : "2" } },
              "DO" : [
                { "drupal_message" : { "message" : "No Copies of this book available!", "type" : "error" } }
              ]
            },
            {
              "ELSE IF" : { "text_matches" : { "text" : [ "check" ], "match" : "3" } },
              "DO" : [
                { "drupal_message" : { "message" : "You cannot issue more than 4 books", "type" : "error" } }
              ]
            },
            { "ELSE" : [
                { "drupal_message" : {
                    "message" : "You have already issued one copy of this book!",
                    "type" : "error"
                  }
                }
              ]
            }
          ]
        }
      ]
    }
  }');
  $items['rules_issue_fields'] = entity_import('rules_config', '{ "rules_issue_fields" : {
      "LABEL" : "Issue fields",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "custom_library" ],
      "ACCESS_EXPOSED" : "1",
      "USES VARIABLES" : { "issue" : { "label" : "Issue", "type" : "node" } },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "issue" ],
            "type" : "node",
            "bundle" : { "value" : { "issue" : "issue" } }
          }
        }
      ],
      "DO" : [
        { "component_rules_return" : { "issue" : [ "issue" ] } },
        { "data_set" : { "data" : [ "issue:field-status" ], "value" : "Returned" } },
        { "data_set" : {
            "data" : [ "issue:field-return-date" ],
            "value" : [ "site:current-date" ]
          }
        },
        { "custom_library_fine_calculation" : {
            "USING" : { "issue" : [ "issue" ] },
            "PROVIDE" : { "fine" : { "fine" : "The fine to be paid by the member" } }
          }
        },
        { "data_set" : { "data" : [ "issue:field-fine" ], "value" : [ "fine" ] } },
        { "entity_save" : { "data" : [ "issue" ], "immediate" : "1" } }
      ]
    }
  }');
  $items['rules_issue_librarian_1'] = entity_import('rules_config', '{ "rules_issue_librarian_1" : {
      "LABEL" : "Issue (Librarian)",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "REQUIRES" : [ "custom_library", "rules_conditional", "rules" ],
      "ACCESS_EXPOSED" : "1",
      "USES VARIABLES" : {
        "book" : { "label" : "Book", "type" : "node" },
        "user" : { "label" : "user", "type" : "user" }
      },
      "ACTION SET" : [
        { "custom_library_issue_check_librarian" : {
            "USING" : { "book" : [ "book" ], "user" : [ "user" ] },
            "PROVIDE" : { "check" : { "check" : "The Status of the action" } }
          }
        },
        { "CONDITIONAL" : [
            {
              "IF" : { "text_matches" : { "text" : [ "check" ], "match" : "1" } },
              "DO" : [
                { "entity_create" : {
                    "USING" : {
                      "type" : "node",
                      "param_type" : "transaction",
                      "param_title" : "Transaction",
                      "param_author" : [ "site:current-user" ]
                    },
                    "PROVIDE" : { "entity_created" : { "entity_created" : "Created entity" } }
                  }
                },
                { "data_set" : { "data" : [ "entity-created:field-user" ], "value" : [ "user" ] } },
                { "data_set" : { "data" : [ "entity-created:field-book" ], "value" : [ "book" ] } },
                { "data_set" : {
                    "data" : [ "entity-created:field-transaction-date" ],
                    "value" : [ "site:current-date" ]
                  }
                },
                { "data_set" : { "data" : [ "entity-created:field-transaction-type" ], "value" : "21" } },
                { "data_set" : { "data" : [ "entity-created:field-no-of-copies" ], "value" : "-1" } },
                { "entity_save" : { "data" : [ "entity-created" ], "immediate" : "1" } },
                { "entity_create" : {
                    "USING" : {
                      "type" : "node",
                      "param_type" : "issue",
                      "param_title" : "Issue",
                      "param_author" : [ "site:current-user" ]
                    },
                    "PROVIDE" : { "entity_created" : { "entity_created1" : "Created entity" } }
                  }
                },
                { "data_set" : { "data" : [ "entity-created1:field-user" ], "value" : [ "user" ] } },
                { "data_set" : { "data" : [ "entity-created1:field-book" ], "value" : [ "book" ] } },
                { "data_set" : {
                    "data" : [ "entity-created1:field-issue-date" ],
                    "value" : [ "site:current-date" ]
                  }
                },
                { "custom_library_return_date" : { "PROVIDE" : { "date" : { "date" : "The return date of the borrowed book" } } } },
                { "data_set" : { "data" : [ "entity-created1:field-return-date" ], "value" : [ "date" ] } },
                { "data_set" : { "data" : [ "entity-created1:field-fine" ], "value" : "0" } },
                { "data_set" : { "data" : [ "entity-created1:field-status" ], "value" : "Issued" } },
                { "entity_save" : { "data" : [ "entity-created1" ], "immediate" : "1" } }
              ]
            },
            {
              "ELSE IF" : { "text_matches" : { "text" : [ "check" ], "match" : "2" } },
              "DO" : [
                { "drupal_message" : { "message" : "No copies of this book available", "type" : "error" } }
              ]
            },
            {
              "ELSE IF" : { "text_matches" : { "text" : [ "check" ], "match" : "3" } },
              "DO" : [
                { "drupal_message" : { "message" : "You cannot issue more than four books!", "type" : "error" } }
              ]
            },
            { "ELSE" : [
                { "drupal_message" : {
                    "message" : "You have already issued one copy of this book!",
                    "type" : "error"
                  }
                }
              ]
            }
          ]
        }
      ]
    }
  }');
  $items['rules_return'] = entity_import('rules_config', '{ "rules_return" : {
      "LABEL" : "Return",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "REQUIRES" : [ "custom_library", "rules" ],
      "ACCESS_EXPOSED" : "1",
      "USES VARIABLES" : { "issue" : { "label" : "Issue", "type" : "node" } },
      "ACTION SET" : [
        { "custom_library_get_id" : { "PROVIDE" : { "id" : { "id" : "The node id of the Issue to be returned" } } } },
        { "entity_fetch" : {
            "USING" : { "type" : "node", "id" : [ "id" ] },
            "PROVIDE" : { "entity_fetched" : { "entity_fetched" : "Fetched entity" } }
          }
        },
        { "entity_create" : {
            "USING" : {
              "type" : "node",
              "param_type" : "transaction",
              "param_title" : "Transaction",
              "param_author" : [ "site:current-user" ]
            },
            "PROVIDE" : { "entity_created" : { "entity_created" : "Created entity" } }
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-user" ],
            "value" : [ "site:current-user" ]
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-book" ],
            "value" : [ "entity-fetched" ]
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-transaction-date" ],
            "value" : [ "site:current-date" ]
          }
        },
        { "data_set" : { "data" : [ "entity-created:field-transaction-type" ], "value" : "22" } },
        { "data_set" : { "data" : [ "entity-created:field-no-of-copies" ], "value" : "1" } },
        { "entity_save" : { "data" : [ "entity-created" ], "immediate" : "1" } }
      ]
    }
  }');
  $items['rules_return_by_librarian'] = entity_import('rules_config', '{ "rules_return_by_librarian" : {
      "LABEL" : "Return by librarian",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "custom_library" ],
      "ACCESS_EXPOSED" : "1",
      "USES VARIABLES" : { "issue" : { "label" : "Issue", "type" : "node" } },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "issue" ],
            "type" : "node",
            "bundle" : { "value" : { "issue" : "issue" } }
          }
        }
      ],
      "DO" : [
        { "custom_library_get_id" : {
            "USING" : { "issue" : [ "issue" ] },
            "PROVIDE" : { "id" : { "id" : "The node id of the book to be returned" } }
          }
        },
        { "entity_fetch" : {
            "USING" : { "type" : "node", "id" : [ "id" ] },
            "PROVIDE" : { "entity_fetched" : { "entity_fetched" : "Fetched entity" } }
          }
        },
        { "entity_create" : {
            "USING" : {
              "type" : "node",
              "param_type" : "transaction",
              "param_title" : "Transaction",
              "param_author" : [ "site:current-user" ]
            },
            "PROVIDE" : { "entity_created" : { "entity_created" : "Created entity" } }
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-user" ],
            "value" : [ "issue:field-user" ]
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-book" ],
            "value" : [ "entity-fetched" ]
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-transaction-date" ],
            "value" : [ "site:current-date" ]
          }
        },
        { "data_set" : { "data" : [ "entity-created:field-transaction-type" ], "value" : "22" } },
        { "data_set" : { "data" : [ "entity-created:field-no-of-copies" ], "value" : "1" } },
        { "entity_save" : { "data" : [ "entity-created" ], "immediate" : "1" } },
        { "data_set" : { "data" : [ "issue:field-status" ], "value" : "Returned" } },
        { "data_set" : {
            "data" : [ "issue:field-return-date" ],
            "value" : [ "site:current-date" ]
          }
        },
        { "custom_library_fine_calculation" : {
            "USING" : { "issue" : [ "issue" ] },
            "PROVIDE" : { "fine" : { "fine" : "The fine to be paid by the member" } }
          }
        },
        { "data_set" : { "data" : [ "issue:field-fine" ], "value" : [ "fine" ] } },
        { "entity_save" : { "data" : [ "issue" ], "immediate" : "1" } }
      ]
    }
  }');
  $items['rules_test'] = entity_import('rules_config', '{ "rules_test" : {
      "LABEL" : "Test",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_login" : [] },
      "DO" : [ { "drupal_message" : { "message" : "You have logged in" } } ]
    }
  }');
  return $items;
}
