<?php
/**
 * @file
 * ec_casestudy.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ec_casestudy_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "cer" && $api == "default_cer_presets") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "panelizer" && $api == "panelizer") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ec_casestudy_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function ec_casestudy_node_info() {
  $items = array(
    'case_study' => array(
      'name' => t('Case Study'),
      'base' => 'node_content',
      'description' => t('A project case study, including project description and photos.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_rdf_default_mappings().
 */
function ec_casestudy_rdf_default_mappings() {
  $schemaorg = array();

  // Exported RDF mapping: case_study
  $schemaorg['node']['case_study'] = array(
    'rdftype' => array(
      0 => 'schema:ScholarlyArticle',
      1 => 'sioc:Item',
      2 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'field_a_b_test_page' => array(
      'predicates' => array(),
    ),
    'field_button_text' => array(
      'predicates' => array(),
    ),
    'field_call_to_action' => array(
      'predicates' => array(),
    ),
    'field_casestudy_location' => array(
      'predicates' => array(),
    ),
    'field_case_study_year_built' => array(
      'predicates' => array(),
    ),
    'field_case_study_square_footage' => array(
      'predicates' => array(),
    ),
    'field_case_study_rooms' => array(
      'predicates' => array(),
    ),
    'field_case_study_energy_before' => array(
      'predicates' => array(),
    ),
    'field_case_study_energy_after' => array(
      'predicates' => array(),
    ),
    'field_case_study_issues' => array(
      'predicates' => array(),
    ),
    'field_ref_case_study_gallery' => array(
      'predicates' => array(),
    ),
    'field_ref_case_study_galley_befo' => array(
      'predicates' => array(),
    ),
    'field_case_study_project_outcome' => array(
      'predicates' => array(),
    ),
    'field_case_study_diagnosis' => array(
      'predicates' => array(),
    ),
    'field_ref_case_study_serv_cat' => array(
      'predicates' => array(),
    ),
    'field_ref_case_study_service' => array(
      'predicates' => array(),
    ),
    'field_case_study_featured_image' => array(
      'predicates' => array(),
      'type' => 'rel',
    ),
    'field_case_study_location' => array(
      'predicates' => array(),
    ),
  );

  return $schemaorg;
}

/**
 * Implements hook_weight_features_default_settings().
 */
function ec_casestudy_weight_features_default_settings() {
  $settings = array();

  $settings['case_study'] = array(
    'enabled' => 1,
    'range' => 20,
    'menu_weight' => 0,
    'default' => 0,
    'sync_translations' => 0,
  );

  return $settings;
}
